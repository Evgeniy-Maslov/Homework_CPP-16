#include <iostream>
#include <string>
#include <fstream>


class LogCommand
{ 
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};


class ConsolLogCommand : public LogCommand
{
public:
    ~ConsolLogCommand() override { }
    void print(const std::string& message) override
    {
        std::cout << "Consol - " << message << std::endl;
    }
};

class FileLogCommand : public LogCommand
{
public:
    ~FileLogCommand() override { }
    void print(const std::string& message) override
    {
        std::ofstream fout("file_log.txt");
        fout << "File - " << message << std::endl;
        fout.close();
    }
};

void print(LogCommand& log_command)
{
    log_command.print("Hello World!!!");
}

int main()
{
    ConsolLogCommand consol_log_command; 
    FileLogCommand file_log_command;

    print(consol_log_command);
    print(file_log_command);

    return 0;
}
