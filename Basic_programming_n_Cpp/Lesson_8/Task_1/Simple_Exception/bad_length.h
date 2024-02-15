#pragma once
#include <string>

class bad_length : public std::exception {
public:
    bad_length(const char* message);
};