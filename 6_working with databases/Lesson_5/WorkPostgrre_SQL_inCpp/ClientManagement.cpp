#include "ClientManagement.h"
#include "functions.h"
#include <pqxx/pqxx>
#include <iostream>


ClientManagement::ClientManagement()  {}
void ClientManagement::CreateDB(pqxx::connection& cx) {
	pqxx::work tx(cx);
	int count_id{};
	tx.exec("CREATE TABLE IF NOT EXISTS Client( "
		"Client_id SERIAL PRIMARY KEY, "
		"first_name VARCHAR(60) NOT NULL, "
		"last_name VARCHAR(60) NOT NULL, "
		"email VARCHAR(60) NOT NULL UNIQUE)");

	tx.exec("CREATE TABLE IF NOT EXISTS Phone( "
		"number_phone_id SERIAL PRIMARY KEY, "
		"number_phone NUMERIC UNIQUE, "
		"client_id INTEGER REFERENCES Client ON DELETE CASCADE)");

	for (auto [it] : tx.query<int>("SELECT COUNT(client_id) FROM Client ")){
		count_id = it;
	}
	if (count_id == 0) {
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
	}
	tx.commit();
}

void ClientManagement::PrintDBClients(pqxx::connection& cx) {
	pqxx::work tx(cx);
	pqxx::result r = tx.exec("SELECT Client.client_id, first_name, last_name, email, number_phone_id, number_phone "
							 "FROM Client LEFT JOIN phone "
							 "ON client.client_id = phone.client_id "
							 "ORDER BY client.client_id, phone.number_phone_id;");
	tx.commit();
	for (auto row : r) {
		for (auto elem : row) {
			std::cout << std::left << std::setw(5) << " " << elem << " " << std::setw(5);
		}
		std::cout << std::endl;
	}
} 

void ClientManagement::AddNewClient(pqxx::connection& cx, std::string& l_name, std::string& f_name, std::string& email, std::string& number_phone) {
	pqxx::work tx(cx);
	std::string client_id{};
	for (auto [it] : tx.query<std::string>("INSERT INTO Client (first_name, last_name, email) VALUES "
		"('" + tx.esc(f_name) + "', '" + tx.esc(l_name) + "', '" + tx.esc(email) + "') RETURNING client_id")) {
		client_id = it;
	}
	if(number_phone != ""){
		tx.exec("INSERT INTO Phone (number_phone, client_id) VALUES "
				"('" + tx.esc(number_phone) + "', '"+ tx.esc(client_id) + "')");
	}
	tx.commit();
}

void ClientManagement::AddPhoneForExistingClient(pqxx::connection& cx, std::string& f_name, std::string& l_name, std::string& number_phone, int& n_client_id) {
	pqxx::work tx(cx);
	tx.exec("INSERT INTO Phone (number_phone, client_id) "
			"VALUES ('" + tx.esc(number_phone) + "', (SELECT client_id "
													"FROM client "
													"WHERE first_name='" + tx.esc(f_name) + "' AND last_name='" + tx.esc(l_name) + "' "
													"ORDER BY client_id "
													"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_client_id - 1)) + "'));");
	tx.commit();
}

void ClientManagement::ChangeCustomerEmail(pqxx::connection& cx, std::string& f_name, std::string& l_name, int& n_client_id, std::string& email) {
	pqxx::work tx(cx);
	tx.exec("UPDATE Client "
			"SET  email='" + tx.esc(email) + "' "
			"WHERE Client.client_id = (SELECT client_id "
										"FROM client "
										"WHERE first_name='" + tx.esc(f_name) + "' AND last_name='" + tx.esc(l_name) + "' "
										"ORDER BY client_id "
										"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_client_id - 1)) + "');");
	tx.commit();
}

void ClientManagement::ChangeCustomerPhone(pqxx::connection& cx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id, std::string& phone_number) {
	pqxx::work tx(cx);
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
	tx.commit();
}

void ClientManagement::DeletePhoneFromExistingClient(pqxx::connection& cx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id) {
	pqxx::work tx(cx);
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
	tx.commit();
}

void ClientManagement::DeleteExistingClient(pqxx::connection& cx, std::string& f_name, std::string& l_name, int& n_client_id) {
	pqxx::work tx(cx);
	tx.exec("DELETE FROM Client "
			"WHERE client_id = (SELECT client_id "
								"FROM Client "
								"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
								"GROUP BY client_id "
								"ORDER BY client_id "
								"LIMIT 1 OFFSET '" + tx.esc(std::to_string(n_client_id - 1)) + "')");
	tx.commit();
}

void ClientManagement::FindClientByHisData(pqxx::connection& cx, std::string& str) {
	pqxx::work tx(cx);
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

ClientManagement::~ClientManagement() {}

