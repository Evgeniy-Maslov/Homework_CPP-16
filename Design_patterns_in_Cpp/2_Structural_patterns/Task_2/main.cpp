#include <map>
#include <string>
#include <iostream>

class VeryHeavyDatabase
{
public:
	std::string GetData(const std::string& key) const noexcept
	{
		return "Very Big Data String: " + key;
	}
};

class CacheDB : public VeryHeavyDatabase
{
	std::map<std::string, std::string> _cache_;
	std::unique_ptr<VeryHeavyDatabase> _real_DB_;
public:
	CacheDB(std::unique_ptr<VeryHeavyDatabase> real_DB) : _real_DB_(std::move(real_DB)) {}

	std::string GetData(const std::string& key)
	{														
		if (_cache_.find(key) == _cache_.end())				
		{
			std::cout << "Read from real DB - ";				
			_cache_[key] = _real_DB_->GetData(key);			
		}
		else
		{
			std::cout << "Read from cache - ";
		}
		return _cache_.at(key);								
	}														
};


class OneShotDB : public VeryHeavyDatabase 
{
	std::unique_ptr<VeryHeavyDatabase> _real_object_;
	size_t _shots_;
public:
	explicit OneShotDB(std::unique_ptr<VeryHeavyDatabase> real_object, size_t shots = 1) : _real_object_(std::move(real_object)), _shots_(shots){}
	
	std::string GetData(const std::string& key)
	{
		if (_shots_ != 0)
		{
			std::cout << "Read from real DB - ";				
			_shots_--;
			return _real_object_->GetData(key);
		}
		else
		{
			return "Error";
		}
	}
};


std::unique_ptr<CacheDB> init_cache()
{
	auto original_db = std::make_unique<VeryHeavyDatabase>(); 
	return std::make_unique<CacheDB>(std::move(original_db));
}

int main()
{
	auto DB = init_cache();
	std::cout << DB->GetData("key_1") << std::endl;
	std::cout << DB->GetData("key_1") << std::endl;
	std::cout << DB->GetData("key_2") << std::endl;

	std::cout << std::endl;
	auto limit_db = std::make_unique<OneShotDB>(std::move(DB), 2);
	std::cout << limit_db->GetData("key") << std::endl;
	std::cout << limit_db->GetData("key") << std::endl;
	std::cout << limit_db->GetData("key") << std::endl;
	std::cout << limit_db->GetData("key") << std::endl;

	return 0;
}
