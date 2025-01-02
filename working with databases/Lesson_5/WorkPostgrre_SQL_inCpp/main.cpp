#include "ClientManagement.h"
#include <pqxx/pqxx>
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>



void pause(char& x) {
	std::cout << "\nTo continue, press any key - ";
	std::cin >> x;
	std::cout << "\n";
}

int main(int argc, char** argv) {
	SetConsoleCP(65001); 
	SetConsoleOutputCP(65001);

	try {
		char x;
		pqxx::connection cx(
		    "host=localhost "
			"port=5432 "
			"dbname=ClientManagement "
			"user=postgres "
			"password=qwerty");
		ClientManagement CM;
		CM.ÑreateDB(cx);
		CM.PrintDBClients(cx);
		pause(x);
		CM.AddNewClient(cx);
		CM.PrintDBClients(cx);
		pause(x);
		CM.AddPhoneForExistingClient(cx);
		CM.PrintDBClients(cx);
		pause(x);
		CM.DeletePhoneFromExistingClient(cx);
		CM.PrintDBClients(cx);
		pause(x);
		CM.ChangeCustomerInformation(cx);
		CM.PrintDBClients(cx);
		pause(x);
		CM.DeleteExistingClient(cx);
		CM.PrintDBClients(cx);
		pause(x);
		CM.FindClientByHisData(cx);
	}
	catch (std::exception const & ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}