#include"function.h"

int function(std::string str, int forbidden_length)
{
    if (str.length() != forbidden_length)
        return str.length();
    throw bad_length("You have entered a word of forbidden length! Goodbye");
}