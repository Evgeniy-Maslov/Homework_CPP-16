#include <string>
#include <vector>


class Report
{
public:
    ~Report() = default;
    virtual std::vector<std::string> get_report() = 0;
};

class Report_v1 : public Report 
{
public:
    std::string _data = "Hello world";
    std::vector<std::string> get_report() override
    {
        std::vector<std::string> arr_elements;
        arr_elements.push_back(_data);
        return arr_elements;
    }
    ~Report_v1() = default;
};

class Report_v2 : public Report
{
public:
    std::string _date = "10.03.2025";
    std::string _title = "report";
    std::string _content = "Hello world";
    std::vector<std::string> get_report() override
    {
        std::vector<std::string> arr_elements;
        arr_elements.push_back(_date);
        arr_elements.push_back(_title);
        arr_elements.push_back(_content);
        return arr_elements;
    }
    ~Report_v2() = default;
};

class Report_v3 : public Report
{
public:
    std::string _date = "10.03.2025";
    std::string _price = "0$";
    std::string _content = "Hello world";
    std::string _reprter_name = "Evgeniy";
    std::vector<std::string> get_report() override
    {
        std::vector<std::string> arr_elements;
        arr_elements.push_back(_date);
        arr_elements.push_back(_price);
        arr_elements.push_back(_content);
        arr_elements.push_back(_reprter_name);
        return arr_elements;
    }
};

