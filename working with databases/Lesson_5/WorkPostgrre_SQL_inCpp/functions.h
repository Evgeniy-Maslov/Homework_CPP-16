#pragma once
#include <pqxx/pqxx>
#include "ClientManagement.h"

void SelectCountClientId(pqxx::connection&, std::string&, std::string&, std::string&);
void ClusterChangePhone(ClientManagement&, pqxx::connection&, std::string&, std::string&, int&, int&);
void ClusterDeletePhone(ClientManagement&, pqxx::connection&, std::string&, std::string&, int&, int&);
