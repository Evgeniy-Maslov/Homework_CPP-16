#include <string>
#include <fstream>
#include <iostream>



class Data 
{
public:

    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };
    Data() {}
    Data(std::string data, Format format) 
        : data_(std::move(data)), format_(format) {
    }
    ~Data()
    {
        data_.clear();
    }
    Format get_format()
    {
        return format_;
    }
    std::string get_data()
    {
        return data_;
    }
    void set_fields(std::string data, Format format)
    {
        data_ = std::move(data);
        format_ = format;
    }
private:
    std::string data_{};
    Format format_{};
};

//===============================================================

class InterAsHTML 
{
public:
    virtual ~InterAsHTML() = default;
    virtual std::string printAsHTML() const = 0;
};

class InterAsText 
{
public:
    virtual ~InterAsText() = default;
    virtual std::string printAsText() const = 0;
};

class InterAsJSON 
{
public:
    virtual ~InterAsJSON() = default;
    virtual std::string printAsJSON() const = 0;
};

//=================================================================

class AsHTML : public InterAsHTML
{
    Data* _D_;
public:
    AsHTML(std::string data, Data::Format format)
    {
        _D_ = new Data();
        _D_->set_fields(data, format);
    }
    std::string printAsHTML() const override
    {
        if (_D_->get_format() != Data::Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + _D_->get_data() + "<html/>";
    }
};

class AsText : public InterAsText
{
    Data* _D_;
public:
    AsText(std::string data, Data::Format format)
    {
        _D_ = new Data();
        _D_->set_fields(data, format);
    }
    std::string printAsText() const override
    {
        if (_D_->get_format() != Data::Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return _D_->get_data();
    }
};

class AsJSON : public InterAsJSON
{
    Data* _D_;
public:
    AsJSON(std::string data, Data::Format format)
    {
        _D_ = new Data();
        _D_->set_fields(data, format);
    }
    std::string printAsJSON() const override
    {
        if (_D_->get_format() != Data::Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + _D_->get_data() + "\"}";
    }
};

void saveToAsHTML(std::ofstream& file, const InterAsHTML& HTML) {
    file << HTML.printAsHTML();
}

void saveToAsJSON(std::ofstream& file, const InterAsJSON& Text) {
    file << Text.printAsJSON();
}

void saveToAsText(std::ofstream& file, const InterAsText& JSON) {
    file << JSON.printAsText();
}



int main()
{
    std::ofstream file("file.txt");
    std::string data("Hello World.");

    try
    {
        InterAsHTML* kHTML = new AsHTML(data, Data::Format::kHTML);
        InterAsJSON* kJSON = new AsJSON(data, Data::Format::kJSON);
        InterAsText* kText = new AsText(data, Data::Format::kText);

        saveToAsHTML(file, *kHTML);
        file << std::endl;
        saveToAsJSON(file, *kJSON);
        file << std::endl;
        saveToAsText(file, *kText);
        file << std::endl;
    }
    catch (std::runtime_error& err)
    {
        std::cout << err.what() << std::endl;
    }
	return 0;
}