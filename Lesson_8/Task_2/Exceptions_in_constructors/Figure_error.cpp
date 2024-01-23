#include"Figure_error.h"



Figure_error::Figure_error(const char* message) : std::domain_error(message)
{
    this->message = message;
}
const char* Figure_error::getMessage()
{
    const char* Error = "Error creating the shape. Reason: ";
    return Error;
}
const char* Figure_error::what() const
{
    return (message);
}