#include <functional>
#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    double a = 30;
    double b = 60;
    double c = 90;
    std::vector<double> angles = { a * 3.1415926 / 180 ,b * 3.1415926 / 180, c * 3.1415926 / 180 };
    auto std::functions();

    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
}
