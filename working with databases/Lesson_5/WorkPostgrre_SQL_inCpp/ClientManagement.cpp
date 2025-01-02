#include "ClientManagement.h"
#include <pqxx/pqxx>
#include <iostream>


ClientManagement::ClientManagement()  {}
void ClientManagement::ÑreateDB(pqxx::connection& cx) {
	try {
		pqxx::work tx(cx);
		tx.exec("CREATE TABLE IF NOT EXISTS Client( "
			"Client_id SERIAL PRIMARY KEY, "
			"first_name VARCHAR(60) NOT NULL, "
			"last_name VARCHAR(60) NOT NULL, "
			"email VARCHAR(60) NOT NULL UNIQUE)");

		tx.exec("CREATE TABLE IF NOT EXISTS Phone( "
			"number_phone_id SERIAL PRIMARY KEY, "
			"number_phone NUMERIC UNIQUE, "
			"client_id INTEGER REFERENCES Client ON DELETE CASCADE)");

		tx.exec("INSERT INTO Client (first_name, last_name, email) VALUES "
			"('Evgeniy', 'Maslov', 'evgeniy@mail.ru'), "
			"('Ivan', 'Petrov', 'one_ivan@mail.ru'), "
			"('Petr', 'Ivanov', 'one_petr@mail.ru'), "
			"('Petr', 'Ivanov', 'tho_petr@mail.ru'), "
			"('Nikolay', 'Nikolaev', 'nikolay@mail.ru'), "
			"('James', 'Bond', 'james@mail.ru');");

		tx.exec("INSERT INTO Phone(number_phone, client_id) VALUES "
			"('12345678', '1'), "
			"('23456789', '2'), "
			"('34567890', '3'), "
			"('45678901', '4'), "
			"('56789012', '4'), "
			"('67890123', '5');");
		tx.commit();
	}
	catch(std::exception const& ex) {
		std::cout << "CreateDB " << ex.what() << std::endl;
	}
	std::cout << "The database has been created \n\n";
}

void ClientManagement::PrintDBClients(pqxx::connection& cx) {
	pqxx::work tx(cx);
	pqxx::result r = tx.exec("SELECT Client.client_id, first_name, last_name, email, number_phone_id, number_phone "
							 "FROM Client LEFT JOIN phone "
							 "ON client.client_id = phone.client_id "
							 "ORDER BY client.client_id;");
	tx.commit();
	for (auto row : r) {
		for (auto elem : row) {
			std::cout << std::left << std::setw(5) << " " << elem << " " << std::setw(5);
		}
		std::cout << std::endl;
	}
} 

void ClientManagement::AddNewClient(pqxx::connection& cx) {
	pqxx::work tx(cx);
	std::cout << "Enter the first and last name of the client you want to add:\n";
	std::string f_name = "Petr";
	std::string l_name = "Petrov";
	//f_name = ""; l_name = "";
	std::string client_id;
	if (f_name == "" and l_name == "") {
		std::cin >> f_name >> l_name;
	}
	else { std::cout << f_name << " " << l_name << "\n\n"; }
	std::cout << "Enter email address:\n";
	std::string email = "Petr@mail.ru";
	//email = "";
	if (email == "") {
		std::cin >> email;
	}
	else { std::cout << email << "\n\n"; }
	for (auto [it] : tx.query<std::string>("INSERT INTO Client (first_name, last_name, email) VALUES "
		"('" + tx.esc(f_name) + "', '" + tx.esc(l_name) + "', '" + tx.esc(email) + "') RETURNING client_id")) {
		client_id = it;
	}
	std::cout << "Do you want to enter a phone number ? \n";
	std::cout << "Click 'y' or 'n':\n";
	std::string YorN;
	std::cin >> YorN;
	if (YorN == "y" or YorN == "Y") {
		std::cout << "Enter the phone number.\n";
		std::string number_phone = "98765432";
		//number_phone = "";
		if (number_phone == "") {
			std::cin >> number_phone;
		}
		else { std::cout << number_phone << "\n\n"; }
		tx.exec("INSERT INTO Phone (number_phone, client_id) VALUES "
				"('" + tx.esc(number_phone) + "', '"+ tx.esc(client_id) + "')");
	}
	tx.commit();
	std::cout << "New client added.\n\n";
}

void ClientManagement::AddPhoneForExistingClient(pqxx::connection& cx) {
	pqxx::work tx(cx);
	std::cout << "Enter the first and last name of the customer who needs to add a new phone number:\n";
	std::string f_name = "Petr";
	std::string l_name = "Ivanov";
	//f_name = ""; l_name = "";
	std::string count_client_id;
	int n_client_id = 1;
	if (f_name == "" and l_name == "") {
		std::cin >> f_name >> l_name;
	}
	else { std::cout << f_name << " " << l_name << "\n\n"; }
	SelectCountClientId(tx, f_name, l_name, count_client_id);
	if (count_client_id == "1") {
		std::string phone_number = "87654321";
		//std::string phone_number{};
		AddPhone(tx, f_name, l_name, phone_number, n_client_id);
	}
	else {
		std::cout << "There are " + count_client_id + " clients with the first and last name " + f_name + " " + l_name + "!\n";
		std::cout << "Who do you want to add a phone number to?\n";
		std::cout << "Choose from 1 to " + count_client_id + ":\n";
		std::cin >> n_client_id;
		std::string phone_number = "76543219";
		//std::string phone_number{};
		AddPhone(tx, f_name, l_name, phone_number, n_client_id);
	}
	n_client_id = 1;
	tx.commit();
	std::cout << "Phone number added.\n\n";
}

void ClientManagement::ChangeCustomerInformation(pqxx::connection& cx) {
	pqxx::work tx(cx);
	std::cout << "Enter the first and last name of the client who needs to change the data:\n";
	std::string f_name = "Petr";
	std::string l_name = "Ivanov";
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
		std::string email = "three_petr@mail.ru";
		//std::string email{};
		if (email == "") { 
			std::cin >> email; 
		}
		else { std::cout << email << "\n\n"; }
		std::string count_client_id;
		int n_client_id = 1;
		SelectCountClientId(tx, f_name, l_name, count_client_id);
		if (count_client_id == "1") {
			ChangeEmail(tx, f_name, l_name, n_client_id, email);
		}
		else {
			std::cout << "There are " + count_client_id + " clients with the first and last name " + f_name + " " + l_name + "!\n"; 
			std::cout << "To which of them do you want to change the email?\n";
			std::cout << "Choose from 1 to " + count_client_id + ":\n";
			std::cin >> n_client_id;
			ChangeEmail(tx, f_name, l_name, n_client_id, email);
		}
		n_client_id = 1;
		tx.commit();
		std::cout << "Email updated\n\n";
	}
	else if (n_enter == "2") {
		std::string count_number_phone;
		int n_number_phone_id = 1;
		int n_client_id = 1;
		std::string count_client_id;
		SelectCountClientId(tx, f_name, l_name, count_client_id);
		if (count_client_id == "1") {
			ClusterChangePhone(tx, f_name, l_name, n_client_id, n_number_phone_id, count_number_phone);
			n_client_id = 1;
		}
		else {
			std::cout << "There are " + count_client_id + " clients with the first and last name " + f_name + " " + l_name + "!\n";
			std::cout << "To which of them do you want to change the phone number?\n";
			std::cout << "Choose from 1 to " + count_client_id + ":\n";
			std::cin >> n_client_id;
			ClusterChangePhone(tx, f_name, l_name, n_client_id, n_number_phone_id, count_number_phone);
			n_number_phone_id = 1;
			n_client_id = 1;
		}
		tx.commit();
		std::cout << "Phone number updated.\n\n";
	}
}

void ClientManagement::DeletePhoneFromExistingClient(pqxx::connection& cx) {
	pqxx::work tx(cx);
	std::cout << "Enter the first and last name of the client who needs to delete the phone:\n";
	std::string f_name = "Petr";
	std::string l_name = "Ivanov";
	//f_name = ""; l_name = "";
	if (f_name == "" and l_name == "") {
		std::cin >> f_name >> l_name;
	}
	else { std::cout << f_name << " " << l_name << "\n\n"; }
	int n_number_phone_id = 1;
	int n_client_id = 1;
	std::string count_client_id;
	SelectCountClientId(tx, f_name, l_name, count_client_id);
	if (count_client_id == "1") {
		ClusterDeletePhone(tx, f_name, l_name, n_client_id, n_number_phone_id);
		n_number_phone_id = 1;
	}
	else {
		std::cout << "There are " + count_client_id + " clients in the database with the first name " + f_name + " and last name " + l_name + "!\n";
		std::cout << "Who do you want to delete the phone from? \n";
		std::cout << "Choose from 1 to " + count_client_id + ":\n";
		std::cin >> n_client_id;
		ClusterDeletePhone(tx, f_name, l_name, n_client_id, n_number_phone_id);
		n_number_phone_id = 1;
		n_client_id = 1;
	}
	tx.commit();
	std::cout << "Phone deleted.\n\n";
}

void ClientManagement::DeleteExistingClient(pqxx::connection& cx) {
	pqxx::work tx(cx);
	std::cout << "Enter the first and last name of the client you want to delete:\n";
	std::string f_name = "Petr";
	std::string l_name = "Ivanov";
	//f_name = ""; l_name = "";
	if (f_name == "" and l_name == "") {
		std::cin >> f_name >> l_name;
	}
	else { std::cout << f_name << " " << l_name << "\n\n"; }
	int n_client_id = 1;
	std::string count_client_id;
	SelectCountClientId(tx, f_name, l_name, count_client_id);
	if (count_client_id == "1") {
		DeleteClient(tx, f_name, l_name, n_client_id);
	}
	else {
		std::cout << "There are "+ count_client_id +" clients in the database with the first name "+ f_name +" and last name "+ l_name +"!\n";
		std::cout << "who do you want to delete?\n";
		std::cout << "Choose from 1 to " + count_client_id + ":\n";
		std::cin >> n_client_id;
		DeleteClient(tx, f_name, l_name, n_client_id);
	}
	n_client_id = 1;
	tx.commit();
	std::cout << "Client deleted.\n\n";
}

void ClientManagement::FindClientByHisData(pqxx::connection& cx) {
	pqxx::work tx(cx);
	std::cout << "To search for a client, enter their first name, last name, email or phone number:\n";
	std::string str = "12345678";
	//str = "";
	if (str == "") {
		std::cin >> str;
	}
	else { std::cout << str << "\n\n"; }
	for (auto [id, f_name, l_name, email, phone] : tx.query<int, std::string, std::string, std::string, int>(
		"SELECT client.client_id, client.first_name, client.last_name, client.email, phone.number_phone "
		"FROM client LEFT JOIN  phone "
		"ON client.client_id = phone.client_id "
		"WHERE client.first_name = '"+ tx.esc(str) +"' "
		"OR client.last_name = '" + tx.esc(str) + "' "
		"OR client.email = '" + tx.esc(str) + "' "
		"OR phone.number_phone::VARCHAR(60) = '" + tx.esc(str) + "';"))
	{
		std::cout << id << ". " << f_name << " " << l_name << ":    email- " << email << ", phone- " << phone << "\n";
	}
	tx.commit();
}

void AddPhone(pqxx::work& tx, std::string& f_name, std::string& l_name, std::string& phone_number, int& n_client_id) {
	std::cout << "Enter a new phone number:\n";
	if (phone_number == "") {
		std::cin >> phone_number;
	}
	else { std::cout << phone_number << "\n\n"; }
	tx.exec("INSERT INTO Phone (number_phone, client_id) "
								"VALUES ('" + tx.esc(phone_number) + "', (SELECT client_id "
								"FROM client "
								"WHERE first_name='" + tx.esc(f_name) + "' AND last_name='" + tx.esc(l_name) + "' "
								"ORDER BY client_id "
								"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_client_id - 1)) + "'));");
}

void SelectCountClientId(pqxx::work& tx, std::string& f_name, std::string& l_name, std::string& count_client_id) {
	for (auto [it] : tx.query<std::string>("SELECT COUNT(client_id) "
											"FROM Client "
											"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "'")) {
		count_client_id = it;
	}
}

void ChangeEmail(pqxx::work& tx, std::string& f_name, std::string& l_name, int& n_client_id, std::string& email) {
	tx.exec("UPDATE Client "
			"SET  email='" + tx.esc(email) + "' "
			"WHERE Client.client_id = (SELECT client_id "
										"FROM client "
										"WHERE first_name='" + tx.esc(f_name) + "' AND last_name='" + tx.esc(l_name) + "' "
										"ORDER BY client_id "
										"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_client_id - 1)) + "');");
}

void ChangePhone(pqxx::work& tx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id, std::string& phone_number) {
	tx.exec("UPDATE Phone "
			"SET number_phone = '" + tx.esc(phone_number) + "' "
			"WHERE Phone.number_phone_id = (SELECT number_phone_id "
											"FROM phone "
											"WHERE client_id = (SELECT client_id "
																"FROM Client "
																"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
																"ORDER BY client_id "
																"LIMIT 1 OFFSET '" + std::to_string(n_client_id - 1) + "') "
											"ORDER BY number_phone_id "
											"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_number_phone_id - 1)) + "');");
}

void ClusterChangePhone(pqxx::work& tx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id, std::string& count_number_phone) {
	for (auto [it] : tx.query<std::string>("SELECT COUNT(phone.number_phone_id) "
											"FROM phone "
											"WHERE client_id = (SELECT client_id "
																"FROM Client "
																"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
																"GROUP BY client_id "
																"ORDER BY client_id "
																"LIMIT 1 OFFSET '" + std::to_string(n_client_id - 1) + "') "
											"GROUP BY client_id")) {
		count_number_phone = it;
	}
	if (count_number_phone == "1") {
		std::cout << "Enter a new phone number:\n";
		std::string phone_number = "56958724";
		//std::string phone_number{};
		if (phone_number == "") {
			std::cin >> phone_number;
		}
		else { std::cout << phone_number << "\n\n"; }
		ChangePhone(tx, f_name, l_name, n_client_id, n_number_phone_id, phone_number);
	}
	else {
		std::cout << f_name + " " + l_name + " has " + count_number_phone + " phone numbers!\n";
		std::cout << "Which phone number do you want to change?\n";
		std::cout << "Choose from 1 to " + count_number_phone + ":\n";
		std::cin >> n_number_phone_id;
		std::cout << "Enter a new phone number:\n";
		std::string phone_number = "56902351";
		//std::string phone_number{};
		if (phone_number == "") {
			std::cin >> phone_number;
		}
		else { std::cout << phone_number << "\n\n"; }
		ChangePhone(tx, f_name, l_name, n_client_id, n_number_phone_id, phone_number);
	}
}

void DeletePhone(pqxx::work& tx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id) {
	tx.exec("DELETE FROM Phone "
			"WHERE phone.number_phone_id = (SELECT number_phone_id "
											"FROM phone "
											"WHERE client_id = (SELECT client_id "
																"FROM Client "
																"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
																"ORDER BY client_id "
																"LIMIT 1 OFFSET '" + std::to_string(n_client_id - 1) + "') "
											"ORDER BY number_phone_id "
											"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_number_phone_id - 1)) + "');");
}

void ClusterDeletePhone(pqxx::work& tx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id) {
	std::string count_number_phone;
	for (auto [it] : tx.query<std::string>("SELECT COUNT(phone.number_phone_id) "
											"FROM phone "
											"WHERE client_id = (SELECT client_id "
																"FROM Client "
																"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
																"GROUP BY client_id "
																"ORDER BY client_id "
																"LIMIT 1 OFFSET '" + std::to_string(n_client_id - 1) + "') "
											"GROUP BY client_id")) {
		count_number_phone = it;
	}
	if (count_number_phone == "1") {
		DeletePhone(tx, f_name, l_name, n_client_id, n_number_phone_id);
	}
	else {
		std::cout << f_name + " " + l_name + " has " + count_number_phone + " phone numbers!\n";
		std::cout << "Which phone number do you want to delete?\n";
		std::cout << "Choose from 1 to " + count_number_phone + ":\n";
		std::cin >> n_number_phone_id;
		DeletePhone(tx, f_name, l_name, n_client_id, n_number_phone_id);
	}
}

void DeleteClient(pqxx::work& tx, std::string& f_name, std::string& l_name, int& n_client_id) {
	tx.exec("DELETE FROM Client "
			"WHERE client_id = (SELECT client_id "
								"FROM Client "
								"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
								"GROUP BY client_id "
								"ORDER BY client_id "
								"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_client_id - 1)) + "')");
}

ClientManagement::~ClientManagement() {}

