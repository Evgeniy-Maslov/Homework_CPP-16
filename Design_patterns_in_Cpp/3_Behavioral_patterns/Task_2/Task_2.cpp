#include <iostream>
#include <fstream>
#include <vector>


class Observer		
{
public:
	virtual void onWarning(const std::string& message) {}
	virtual void onError(const std::string& message) {}
	virtual void onFatalError(const std::string& message) {}
};


class ObservedClass
{
private:
	mutable std::string _message_warning_;
	mutable std::string _message_error_;
	mutable std::string _message_fatalError_;
	std::vector<Observer*> _observers_;
public:
	ObservedClass() = default;
	
	void add_observer(Observer* observer)
	{
		_observers_.push_back(observer);
	}

	enum class types
	{
		warning,
		error,
		fatalError
	};

	void notify(types type) const
	{
		for (Observer* obs : _observers_)
		{
			switch (type)
			{
			case types::warning:
				obs->onWarning(_message_warning_);
				break;
			case types::error:
				obs->onError(_message_error_);
				break;
			case types::fatalError:
				obs->onFatalError(_message_fatalError_);
				break;
			}
		}
	}

	void remove_observer(Observer* observer)	
	{
		auto it = remove(_observers_.begin(), _observers_.end(), observer);
		_observers_.erase(it, _observers_.end());
	}

	void warning(const std::string& message_warning) const
	{	
		_message_warning_ = message_warning;
		notify(types::warning);
	}

	void error(const std::string& message_error) const
	{
		_message_error_ = message_error;
		notify(types::error);
	}

	void fatalError(const std::string& message_fatalError) const
	{
		_message_fatalError_ = message_fatalError;
		notify(types::fatalError);
	}

	~ObservedClass()  = default;
};

class Warning : public Observer
{
	void onWarning(const std::string& message_warning) override
	{
		std::cout << "Warning - " << message_warning << std::endl;
	}
	void onError(const std::string& message_error) override {}
	void onFatalError(const std::string& message_fatalError) override {}
};

class Error : public Observer
{
	void onError(const std::string& message_error) override
	{
		std::ofstream fout("Log_Error.txt");
		fout << "Error - " << message_error << std::endl;
		fout.close();
	}
	void onWarning(const std::string& message_warning) override {}
	void onFatalError(const std::string& message_fatalError) override {}
};

class FatalError : public Observer
{
	void onFatalError(const std::string& message_fatalError) override
	{
		std::cout << "FatalError - " << message_fatalError << std::endl;
		std::ofstream fout("Log_FatalError.txt");
		fout << "FatalError - " << message_fatalError << std::endl;
		fout.close();
	}
	void onWarning(const std::string& message_warning) override {}
	void onError(const std::string& message_error) override {}
};


int main()
{
	ObservedClass OC;

	Warning warn;
	Error err;
	FatalError fat_err;
	OC.add_observer(&warn);
	OC.add_observer(&err);
	OC.add_observer(&fat_err);

	OC.warning("The temperature of the object is higher by 15 %");
	OC.error("The temperature of the object is higher by 30 %");
	OC.fatalError("The temperature of the object is higher by 60 %");

	return 0;
}

