#pragma once
#include <pqxx/pqxx>



class ClientManagement {
public:
	ClientManagement();
	void CreateDB(pqxx::connection&);
	void PrintDBClients(pqxx::connection&);
	void AddNewClient(pqxx::connection&, std::string&, std::string&, std::string&, std::string&);
	void AddPhoneForExistingClient(pqxx::connection&, std::string&, std::string&, std::string&, int&);
	void ChangeCustomerEmail(pqxx::connection&, std::string&, std::string&, int&, std::string&);
	void ChangeCustomerPhone(pqxx::connection&, std::string&, std::string&, int&, int&, std::string&);
	void DeletePhoneFromExistingClient(pqxx::connection&, std::string&, std::string&, int&, int&);
	void DeleteExistingClient(pqxx::connection&, std::string&, std::string&, int&);
	void FindClientByHisData(pqxx::connection&, std::string&);
	~ClientManagement();
};
