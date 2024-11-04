#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <algorithm>



std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main()
{
    std::variant<int, std::string, std::vector<int>> result = get_variant();
    if (std::holds_alternative<int>(result))
    {
        auto n = std::get_if<int>(&result);
        std::cout << (*n *= 2);
    }
    else if (std::holds_alternative<std::string>(result))
    {
        auto str = std::get<std::string >(result);
        std::cout << str;
    }
    else
    {
        auto vec = std::get<std::vector<int>>(result);
        std::for_each(std::begin(vec), std::end(vec), [](int const& value)
            {
            std::cout << value << " ";
            });
    }
    return 0;
}

