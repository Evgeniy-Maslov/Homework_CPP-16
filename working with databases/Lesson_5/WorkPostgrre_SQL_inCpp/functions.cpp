#include "functions.h"
#include "ClientManagement.h"
#include <pqxx/pqxx>
#include <iostream>

void SelectCountClientId(pqxx::connection& cx, std::string& f_name, std::string& l_name, std::string& count_client_id) {
	pqxx::work tx(cx);
	for (auto [it] : tx.query<std::string>("SELECT COUNT(client_id) "
											"FROM Client "
											"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "'")) {
		count_client_id = it;
	}
	tx.commit();
}

void ClusterChangePhone(ClientManagement& CM, pqxx::connection& cx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id) {
	pqxx::work tx(cx);
	int count_number_phone{};
	for (auto [it] : tx.query<int>("SELECT COUNT(phone.number_phone_id) "
											"FROM phone "
											"WHERE client_id = (SELECT client_id "
																"FROM Client "
																"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
																"GROUP BY client_id "
																"ORDER BY client_id "
																"LIMIT 1 OFFSET '" + std::to_string(n_client_id - 1) + "') "
											"GROUP BY client_id")) {
		count_number_phone = it;
		tx.commit();
	}
	if (count_number_phone == 0) {
		std::cout << "Sorry. This client does not have a phone!!!\n\n";
	}
	else if (count_number_phone == 1) {
		std::cout << "Enter a new phone number:\n";
		std::string phone_number = "56958724";
		//std::string phone_number{};
		if (phone_number == "") {
			std::cin >> phone_number;
		}
		else { std::cout << phone_number << "\n\n"; }
		CM.ChangeCustomerPhone(cx, f_name, l_name, n_client_id, n_number_phone_id, phone_number);
		std::cout << "Phone number updated.\n\n";
	}
	else {
		std::cout << f_name + " " + l_name + " has " + std::to_string(count_number_phone) + " phone numbers!\n";
		std::cout << "Which phone number do you want to change?\n";
		std::cout << "Choose from 1 to " + std::to_string(count_number_phone) + ":\n";
		std::cin >> n_number_phone_id;
		std::cout << "Enter a new phone number:\n";
		std::string phone_number = "56902351";
		//std::string phone_number{};
		if (phone_number == "") {
			std::cin >> phone_number;
		}
		else { std::cout << phone_number << "\n\n"; }
		CM.ChangeCustomerPhone(cx, f_name, l_name, n_client_id, n_number_phone_id, phone_number);
		std::cout << "Phone number updated.\n\n";
	}
	n_number_phone_id = 1;
	n_client_id = 1;
}

void ClusterDeletePhone(ClientManagement& CM, pqxx::connection& cx, std::string& f_name, std::string& l_name, int& n_client_id, int& n_number_phone_id) {
	pqxx::work tx(cx);
	int count_number_phone{};
	for (auto [it] : tx.query<int>("SELECT COUNT(phone.number_phone_id) "
											"FROM phone "
											"WHERE client_id = (SELECT client_id "
																"FROM Client "
																"WHERE first_name = '" + tx.esc(f_name) + "' AND last_name = '" + tx.esc(l_name) + "' "
																"GROUP BY client_id "
																"ORDER BY client_id "
																"LIMIT 1 OFFSET '" + std::to_string(n_client_id - 1) + "') "
											"GROUP BY client_id")) {
		count_number_phone = it;
		tx.commit();
	}
	if (count_number_phone == 0) {
		std::cout << "Sorry. This client does not have a phone!!!\n\n";
	}
	else if (count_number_phone == 1) {
		CM.DeletePhoneFromExistingClient(cx, f_name, l_name, n_client_id, n_number_phone_id);
		std::cout << "Phone deleted.\n\n";
	}
	else {
		std::cout << f_name + " " + l_name + " has '" + std::to_string(count_number_phone) + "' phone numbers!\n";
		std::cout << "Which phone number do you want to delete?\n";
		std::cout << "Choose from 1 to '"+ std::to_string(count_number_phone) + "':\n";
		std::cin >> n_number_phone_id;
		CM.DeletePhoneFromExistingClient(cx, f_name, l_name, n_client_id, n_number_phone_id);
		std::cout << "Phone deleted.\n\n";
	}
	f_name = "";
	l_name = "";
	n_number_phone_id = 1;
	n_client_id = 1;
}
