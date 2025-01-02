#pragma once
#include <pqxx/pqxx>



class ClientManagement {
public:
	ClientManagement();
	void ÑreateDB(pqxx::connection&);
	void PrintDBClients(pqxx::connection&);
	void AddNewClient(pqxx::connection&);
	void AddPhoneForExistingClient(pqxx::connection&);
	void ChangeCustomerInformation(pqxx::connection&);
	void DeletePhoneFromExistingClient(pqxx::connection&);
	void DeleteExistingClient(pqxx::connection&);
	void FindClientByHisData(pqxx::connection&);
	friend void AddPhone(pqxx::work&, std::string&, std::string&, std::string&, int&);
	friend void SelectCountClientId(pqxx::work&, std::string&, std::string&, std::string&);
	friend void ChangeEmail(pqxx::work&, std::string&, std::string&, int&, std::string&);
	friend void ChangePhone(pqxx::work&, std::string&, std::string&, int&, int&, std::string&);
	friend void ClusterChangePhone(pqxx::work&, std::string&, std::string&, int&, int&, std::string&);
    friend void DeletePhone(pqxx::work&, std::string&, std::string&, int&, int&);
	friend void ClusterDeletePhone(pqxx::work&, std::string&, std::string&, int&, int&);
	friend void DeleteClient(pqxx::work&, std::string&, std::string&, int&);
	~ClientManagement();
};
