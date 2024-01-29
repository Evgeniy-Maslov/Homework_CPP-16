#pragma once
#include <iostream>

class Figure_error :public std::domain_error
{
    const char* message;
public:
    Figure_error(const char* message);
    const char* getMessage();
    const char* what() const override;
};