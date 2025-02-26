#include <iostream>
#include <fstream>


class LogMessage 
{
    const char* _type_;
    std::string _message_;
public:
    LogMessage(const char* type, const std::string message) : _type_(type), _message_(message) {}
    const char* type() const
    {
        return _type_;
    }
    const std::string& message() const
    {
        return _message_;
    }
};

class MessageHandler
{
public:
    virtual void handle_request(LogMessage* request) = 0;
    virtual void set_next_handler(MessageHandler* handler) = 0;
};

class WarningHandler : public MessageHandler
{
    MessageHandler* _next_ = nullptr;
public:
    void set_next_handler(MessageHandler* handler) override
    {
        _next_ = handler;
    }
    void handle_request(LogMessage* request) override
    {
        if (request->type() == "warning")
        {
            std::cout << request->message() << std::endl;
        }
        else if (_next_ != nullptr)
        {
            _next_->handle_request(request);
        }
        else
        {
            throw "Unknown message type. Not processed!";
        }
    }
};

class ErrorHandler : public MessageHandler
{
    MessageHandler* _next_ = nullptr;
public:
    void set_next_handler(MessageHandler* handler) override
    {
        _next_ = handler;
    }
    void handle_request(LogMessage* request) override
    {
        if (request->type() == "error")
        {
            std::ofstream fout("logError.txt");
            fout << "Error - " << request->message() << std::endl;
            fout.close();
        }
        else if (_next_ != nullptr)
        {
            _next_->handle_request(request);
        }
        else
        {
            throw "Unknown message type. Not processed!";
        }
    }

};

class FatalErrorHandler : public MessageHandler
{
    MessageHandler* _next_ = nullptr;
public:
    void set_next_handler(MessageHandler* handler) override
    {
        _next_ = handler;
    }
    void handle_request(LogMessage* request) override
    {
        if (request->type() == "fatal_error")
        {
            throw request->message();
        }
        else if (_next_ != nullptr)
        {
            _next_->handle_request(request);
        }
        else
        {
            throw "Unknown message type. Not processed!";
        }
    }

};

int main()
{
    LogMessage Warning("warning", "Warning received");
    LogMessage Error("error", "An error occurred");
    LogMessage FatalError("fatal_error", "A fatal error occurred");
    LogMessage Unknown("unknown", "An unknown message was received");

    MessageHandler* Warn = new WarningHandler();
    MessageHandler* Err = new ErrorHandler();
    MessageHandler* FatErr = new FatalErrorHandler();

    FatErr->set_next_handler(Err);
    Err->set_next_handler(Warn);
    try 
    {
        FatErr->handle_request(&Warning);
        FatErr->handle_request(&Error);
        FatErr->handle_request(&FatalError);
        FatErr->handle_request(&Unknown);
    }
    catch(const std::string& err)
    {
        std::cout << "An exception was thrown: " << err << std::endl;
    }
    catch (const char* err)
    {
        std::cout << "An exception was thrown: " << err << std::endl;
    }
    return 0;
}

