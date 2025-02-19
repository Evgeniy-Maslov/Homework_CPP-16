#include "ClientManagement.h"
#include "functions.h"
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
	SetConsoleCP(1251);//(65001);
	SetConsoleOutputCP(1251);//(65001);
	std::string f_name{};
	std::string l_name{};
	std::string email{};
	std::string YorN;
	std::string number_phone{};
	std::string count_client_id{};
	int n_number_phone_id = 1;
	int n_client_id = 1;

	try {
		char x;
		pqxx::connection cx(
		    "host=localhost "
			"port=5432 "
			"dbname=ClientManagement "
			"user=postgres "
			"password=qwerty");
		ClientManagement CM;
		CM.CreateDB(cx);
		CM.PrintDBClients(cx);
		pause(x);


		std::cout << "Enter the first and last name of the client you want to add:\n";
		f_name = "Petr";
		l_name = "Petrov";
		//f_name = ""; l_name = "";
		if (f_name == "" and l_name == "") {
			std::cin >> f_name >> l_name;
		}
		else { std::cout << f_name << " " << l_name << "\n\n"; }
		std::cout << "Enter email address:\n";
		email = "Petr@mail.ru";
		//email = "";
		if (email == "") {
			std::cin >> email;
		}
		else { std::cout << email << "\n\n"; }
		std::cout << "Do you want to enter a phone number ? \n";
		std::cout << "Click 'y' or 'n':\n";
		std::cin >> YorN;
		if (YorN == "y" or YorN == "Y") {
			std::cout << "Enter the phone number.\n";
			number_phone = "98765432";
			//number_phone = "";
			if (number_phone == "") {
				std::cin >> number_phone;
			}
			else { std::cout << number_phone << "\n\n"; }
			CM.AddNewClient(cx, l_name, f_name, email, number_phone);
		}
		else {
			CM.AddNewClient(cx, l_name, f_name, email, number_phone);
		}
		f_name = "";
		l_name = "";
		email = "";
		number_phone = "";
		std::cout << "New client added.\n\n";
		CM.PrintDBClients(cx);
		pause(x);


		std::cout << "Enter the first and last name of the customer who needs to add a new phone number:\n";
		f_name = "Petr";
		l_name = "Ivanov";
		//f_name = ""; l_name = "";
		if (f_name == "" and l_name == "") {
			std::cin >> f_name >> l_name;
		}
		else { std::cout << f_name << " " << l_name << "\n\n"; }
		SelectCountClientId(cx, f_name, l_name, count_client_id);
		if (count_client_id == "1") {
			number_phone = "87654321";
			//number_phone = "";
			std::cout << "Enter a new phone number:\n";
			if (number_phone == "") {
				std::cin >> number_phone;
			}
			else { std::cout << number_phone << "\n\n"; }
			CM.AddPhoneForExistingClient(cx, f_name, l_name, number_phone, n_client_id);
		}
		else {
			std::cout << "There are " + count_client_id + " clients with the first and last name " + f_name + " " + l_name + "!\n";
			std::cout << "Who do you want to add a phone number to?\n";
			std::cout << "Choose from 1 to " + count_client_id + ":\n";
			std::cin >> n_client_id;
			number_phone = "76543219";
			//phone_number = "";
			std::cout << "Enter a new phone number:\n";
			if (number_phone == "") {
				std::cin >> number_phone;
			}
			else { std::cout << number_phone << "\n\n"; }
			CM.AddPhoneForExistingClient(cx, f_name, l_name, number_phone, n_client_id);
		}
		f_name = "";
		l_name = "";
		number_phone = "";
		n_client_id = 1;
		std::cout << "Phone number added.\n\n";
		CM.PrintDBClients(cx);
		pause(x);


		std::cout << "Enter the first and last name of the client who needs to delete the phone:\n";
		f_name = "Petr";
		l_name = "Ivanov";
		//f_name = ""; l_name = "";
		if (f_name == "" and l_name == "") {
			std::cin >> f_name >> l_name;
		}
		else { std::cout << f_name << " " << l_name << "\n\n"; }
		SelectCountClientId(cx, f_name, l_name, count_client_id);
		if (count_client_id == "1") {
			ClusterDeletePhone(CM, cx, f_name, l_name, n_client_id, n_number_phone_id);
		}
		else {
			std::cout << "There are " + count_client_id + " clients in the database with the first name " + f_name + " and last name " + l_name + "!\n";
			std::cout << "Who do you want to delete the phone from? \n";
			std::cout << "Choose from 1 to " + count_client_id + ":\n";
			std::cin >> n_client_id;
			ClusterDeletePhone(CM, cx, f_name, l_name, n_client_id, n_number_phone_id);
		}
		CM.PrintDBClients(cx);
		pause(x);


		std::cout << "Enter the first and last name of the client who needs to change the data:\n";
		f_name = "Petr";
		l_name = "Ivanov";
		//f_name = ""; l_name = "";
		if (f_name == "" and l_name == "") {
			std::cin >> f_name >> l_name;
		}
		else { std::cout << f_name << " " << l_name << "\n\n"; }
		std::cout << "What do you want to change? Enter 1 or 2:\n";
		std::cout << "1. Email\n";
		std::cout << "2. Phone number\n";
		std::string n_enter = "1";
		//n = "2";
		std::cin >> n_enter;
		if (n_enter == "1") {
			std::cout << "Enter a new email:\n";
			email = "three_petr@mail.ru";
			//email = "";
			if (email == "") {
				std::cin >> email;
			}
			else { std::cout << email << "\n\n"; }
			SelectCountClientId(cx, f_name, l_name, count_client_id);
			if (count_client_id == "1") {
				CM.ChangeCustomerEmail(cx, f_name, l_name, n_client_id, email);
			}
			else {
				std::cout << "There are " + count_client_id + " clients with the first and last name " + f_name + " " + l_name + "!\n";
				std::cout << "To which of them do you want to change the email?\n";
				std::cout << "Choose from 1 to " + count_client_id + ":\n";
				std::cin >> n_client_id;
				CM.ChangeCustomerEmail(cx, f_name, l_name, n_client_id, email);
			}
			n_client_id = 1;
			std::cout << "Email updated\n\n";
		}
		else if (n_enter == "2") {
			int n_number_phone_id = 1;
			n_client_id = 1;
			SelectCountClientId(cx, f_name, l_name, count_client_id);
			if (count_client_id == "1") {
				ClusterChangePhone(CM, cx, f_name, l_name, n_client_id, n_number_phone_id);
			}
			else {
				std::cout << "There are " + count_client_id + " clients with the first and last name " + f_name + " " + l_name + "!\n";
				std::cout << "To which of them do you want to change the phone number?\n";
				std::cout << "Choose from 1 to " + count_client_id + ":\n";
				std::cin >> n_client_id;
				ClusterChangePhone(CM, cx, f_name, l_name, n_client_id, n_number_phone_id);
			}
		}
		CM.PrintDBClients(cx);
		pause(x);
		 

		std::cout << "Enter the first and last name of the client you want to delete:\n";
		f_name = "Petr";
		l_name = "Ivanov";
		//f_name = ""; l_name = "";
		if (f_name == "" and l_name == "") {
			std::cin >> f_name >> l_name;
		}
		else { std::cout << f_name << " " << l_name << "\n\n"; }
		SelectCountClientId(cx, f_name, l_name, count_client_id);
		if (count_client_id == "1") {
			CM.DeleteExistingClient(cx, f_name, l_name, n_client_id);
		}
		else {
			std::cout << "There are "+ count_client_id +" clients in the database with the first name "+ f_name +" and last name "+ l_name +"!\n";
			std::cout << "who do you want to delete?\n";
			std::cout << "Choose from 1 to " + count_client_id + ":\n";
			std::cin >> n_client_id;
			CM.DeleteExistingClient(cx, f_name, l_name, n_client_id);
		}
		n_client_id = 1;		
		std::cout << "Client deleted.\n\n";
		CM.PrintDBClients(cx);
		pause(x);

		
		std::cout << "To search for a client, enter their first name, last name, email or phone number:\n";
		std::string str = "12345678";
		//str = "";
		if (str == "") {
			std::cin >> str;
		}
		else { std::cout << str << "\n\n"; }
		CM.FindClientByHisData(cx, str);
	}
	catch (std::exception const & ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}