#include <Wt/Dbo/backend/Postgres.h>
#include <Wt/Dbo/Dbo.h>
#include "TablesFoo.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>



int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::vector<std::vector<std::string>> Alexander_Dumas = { {"Alexander Dumas"},
    {"The Count of Monte Cristo", "10", "World of books", "100", "2024-10-30", "6", "2024-11-24", "4"},
    {"The Three Musketeers", "25", "Butik Books", "110", "2024-07-10", "15", "2024-07-15", "10"},
    {"fencing teacher", "30", "Live Book", "200", "2024-08-25", "22", "2024-08-30", "8"} };
    
    std::vector<std::vector<std::string>> Jack_London = { {"Jack London"},
    {"The hearts of the three", "40", "Live Book", "150", "2024-09-10", "25", "2024-09-15", "15"},
    {"The sea wolf", "10","World of books", "130",	"2024-09-11", "7", "2024-09-13", "3"},
    {"The Wanderer through the stars", "15", "Butik Books", "250", "2024-12-05", "7", "2024-12-10", "8"} };

    std::vector<std::vector<std::string>> Mikhail_Lermontov = { {"Mikhail Lermontov"},
    {"Demon", "50", "Butik Books", "90", "2024-11-27","35", "2024-11-28", "15"},
    {"A hero of our time", "60", "Live Book", "120", "2024-10-17", "31", "2024-10-19", "29"},
    {"Mtsyri", "45", "World of books", "105", "2024-06-18", "27", "2024-06-19", "18"}};

    try {
        std::string conectionsString = "host=localhost "
            "port=5432 "
            "dbname=dbORM "
            "user=postgres "
            "password=qwerty";

        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(conectionsString);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));
        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");
        session.mapClass<Shop>("shop");
        int lifecycle = -1;
        while (lifecycle != 0) {
            std::cout << "Enter op" << std::endl
                << "1. Create tables" << std::endl
                << "2. Fill in the tables" << std::endl
                << "3. Publisher information" << std::endl
                << "0. Exit" << std::endl;
                std::cin >> lifecycle;
            try {
                switch (lifecycle){
                case 1: {
                    //session.dropTables();
                    session.createTables();
                    break;
                }
                case 2: {
                    FillTables(session, Alexander_Dumas);
                    FillTables(session, Jack_London);
                    FillTables(session, Mikhail_Lermontov);
                    std::cout << "\nTables created and test data filled!!!\n\n";
                    break;
                }
                case 3: {
                    std::string name = "Jack London";
                    GetInfo(session, name);
                    name = "Mikhail Lermontov";
                    GetInfo(session, name);
                    name = "Alexander Dumas";
                    GetInfo(session, name);
                    break;
                }
                default:
                    break;
                }
            }
            catch (const std::exception& ex) {
                std::cout << "Query failed  " << ex.what() << std::endl;
            }
        }
    }
    catch (const std::exception& ex) {
        std::cout << "Conection failed  " << ex.what() << std::endl;
    }
    return 0;
}

