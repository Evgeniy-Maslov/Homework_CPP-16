#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "Report.cpp"



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

class ReportHandler
{
public:
    ReportHandler()
    {
        set_chain_sequence();
    }

    std::string printer(Report* report, Format::format format)
    {
        if(report->get_report().size() == 1)
        {
            _data = std::move(report->get_report()[0]);
            return print_format[0]->wrap_element(_data, format);
        }
        else
        {
            _arr_data = std::move(report->get_report());
            return print_format[0]->wrap_report(_arr_data, format);
        }
    }

private:
    std::vector<Printer*> print_format
    {
        new PrinterText(),
        new PrinterHTML(),
        new PrinterJSON()
    };
    std::string _data;
    std::vector<std::string> _arr_data;

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

    Report* report_V1 = new Report_v1();
    Report* report_V2 = new Report_v2();
    Report* report_V3 = new Report_v3();
 
    ReportHandler report;
    try
    {
        file << report.printer(report_V1, Format::kHTML) << std::endl;
        file << std::endl;
        file << report.printer(report_V1, Format::kText) << std::endl;
        file << std::endl;
        file << report.printer(report_V1, Format::kJSON) << std::endl;
        file << std::endl;
        file << std::endl;
        file << report.printer(report_V2, Format::kHTML) << std::endl;
        file << std::endl;
        file << report.printer(report_V2, Format::kText) << std::endl;
        file << std::endl;
        file << report.printer(report_V2, Format::kJSON) << std::endl;
        file << std::endl;
        file << std::endl;
        file << report.printer(report_V3, Format::kHTML) << std::endl;
        file << std::endl;
        file << report.printer(report_V3, Format::kText) << std::endl;
        file << std::endl;
        file << report.printer(report_V3, Format::kJSON) << std::endl;
    }
    catch (std::runtime_error& err)
    {
        std::cout << err.what() << std::endl;
    }

    return 0;
}; 