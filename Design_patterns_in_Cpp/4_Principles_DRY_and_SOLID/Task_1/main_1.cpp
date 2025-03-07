#include <string>
#include <fstream>
#include <vector>
#include <iostream>

namespace Format
{
    typedef int format;
    format kText = 0;
    format kHTML = 1;
    format kJSON = 2;
}


class Printer {
public:
    virtual ~Printer() = default;
    virtual std::string wrap_element(const std::string& data, Format::format format) const = 0;
    virtual std::string wrap_report(const std::vector<std::string>& elements, Format::format format) const = 0;
    virtual void set_next_handler(Printer* handler) = 0;
};

class PrinterHTML : public Printer {
    Printer* _next = nullptr;
public:
    ~PrinterHTML() = default;
    void set_next_handler(Printer* handler) override
    {
        _next = handler;
    }
    std::string wrap_element(const std::string& data, Format::format format) const override {
        if (format == Format::kHTML)
        {
            return "<p>" + data + "</p>";
        }
        else if (_next != nullptr)
        {
            return _next->wrap_element(data, format);
            
        }
        else
        {
            throw std::runtime_error("Invalid format!");
        }
    }
    std::string wrap_report(const std::vector<std::string>& elements, Format::format format) const override {
        //TODO: склейка элементов через новую строку и оборачивание в html-тег
        if (format == Format::kHTML)
        {
            std::string _report{};
            for (size_t i = 0; i < elements.size(); i++)
            {
                i == (elements.size() - 1) ? _report += elements[i] : _report += elements[i] + "<br>";
            }
            return "<p>" + _report + "</p>";
        }
        else if (_next != nullptr)
        {
            return _next->wrap_report(elements, format);

        }
        else
        {
            throw std::runtime_error("Invalid format!");
        }
    }
};

class PrinterJSON : public Printer {
    Printer* _next = nullptr;
public:
    ~PrinterJSON() = default;
    void set_next_handler(Printer* handler) override
    {
        _next = handler;
    }
    std::string wrap_element(const std::string& data, Format::format format) const override {
        if (format == Format::kJSON)
        {
            return "{ \"item\": \"" + data + "\"}";
        }
        else if (_next != nullptr)
        {
            return _next->wrap_element(data, format);
            
        }
        else
        {
            throw std::runtime_error("Invalid format!");
        }
    }
    std::string wrap_report(const std::vector<std::string>& elements, Format::format format) const override {
        //TODO: склейка элементов через , и оборачивание в массив - [ elem1, elem2 ]
        if (format == Format::kJSON)
        {
            std::string _report{};
            for (size_t i = 0; i < elements.size(); i++)
            {
                i == (elements.size() - 1) ? _report += elements[i] : _report += elements[i] + ", ";
            }
            return "[ " + _report + " ]";
        }
        else if (_next != nullptr)
        {
            return _next->wrap_report(elements, format);
        }
        else
        {
            throw std::runtime_error("Invalid format!");
        }
    }
};

class PrinterText : public Printer {
    Printer* _next = nullptr;
public:
    ~PrinterText() = default;
    void set_next_handler(Printer* handler) override
    {
        _next = handler;
    }
    std::string wrap_element(const std::string& data, Format::format format) const override {
        if (format == Format::kText)
        {
            return data;
        }
        else if (_next != nullptr)
        {
            return _next->wrap_element(data, format);
        }
        else
        {
            throw std::runtime_error("Invalid format!");
        }
    }
    std::string wrap_report(const std::vector<std::string>& elements, Format::format format) const override {
        //TODO: склейка элементов через новую строку
        if (format == Format::kText)
        {
            std::string _report{};
            for (size_t i = 0; i < elements.size(); i++)
            {
                i == (elements.size() - 1) ? _report += elements[i] : _report += elements[i] + "\n";
            }
            return _report;
        }
        else if (_next != nullptr)
        {
            return _next->wrap_report(elements, format);
        }
        else
        {
            throw std::runtime_error("Invalid format!");
        }
    }
};

class PrintDataProcessor
{
public:
    PrintDataProcessor()
    {
        set_chain_sequence();
    }

    std::string printer(std::string data, Format::format format )
    {
        set_fields(data, {}, format);
        return print_format[0]->wrap_element(_data, _format);
    }
    std::string printer(std::vector<std::string> arr_data, Format::format format)
    {
        set_fields({}, arr_data, format);
        return print_format[0]->wrap_report(_arr_data, _format);
    }
private:
    std::vector<Printer*> print_format
    {
        new PrinterText(),
        new PrinterHTML(),
        new PrinterJSON()
    };
    Format::format _format{};
    std::string _data;
    std::vector<std::string> _arr_data;

    void set_fields(std::string data, std::vector<std::string> arr_data, Format::format format)
    {
        _data = std::move(data);
        _arr_data = std::move(arr_data);
        _format = format;
    }

    void set_chain_sequence()
    {
        for (size_t i = 0; i < print_format.size() - 1; i++)
        {
            print_format[i]->set_next_handler(print_format[i + 1]);
        }
    }
};


int main()
{
    std::ofstream file("file.txt");
    std::string data("Hello World.");
    std::vector<std::string> arr_data{ "hello", "world", "Chain of Responsibility", "Single responsibility principle" };
    
    PrintDataProcessor report;
    try
    {
        file << report.printer(data, Format::kHTML) << std::endl;
        file << std::endl;
        file << report.printer(data, Format::kText) << std::endl;
        file << std::endl;
        file << report.printer(data, Format::kJSON) << std::endl;
        file << std::endl;
        file << std::endl;
        file << report.printer(arr_data, Format::kHTML) << std::endl;
        file << std::endl;
        file << report.printer(arr_data, Format::kJSON) << std::endl;
        file << std::endl;
        file << report.printer(arr_data, Format::kText) << std::endl;
    }
    catch(std::runtime_error& err)
    {
        std::cout << err.what() << std::endl;
    }
   
    return 0;
}