#include "Air_Race.h"
#include "Ground_and_Air_Race.h"
#include "Ground_Race.h"
#include <iostream>
#include "General_Functions.h"
#include "Header_DLL.h"


using namespace my_space;

enum class Types
{
	Ground_race = 1,
	Air_race,
	Ground_and_air_race
};

void out_select_type_of_race(int& a)
{
	std::cout << std::endl;
	std::cout << "1. Ground race" << std::endl;
	std::cout << "2. Air race" << std::endl;
	std::cout << "3. Ground and air race" << std::endl;
	do
	{
		std::cout << "select type of race: ";
		std::cin >> a;
	} while (a < 1 || a > 3);
}

std::string select_type_of_race(int& a)		// ¬€¡Œ– “»œ¿ √ŒÕŒ  
{
	if (static_cast<Types>(a) == Types::Ground_race) { return "Ground race. Distance: "; }
	else if (static_cast<Types>(a) == Types::Air_race) { return "Air race. Distance: "; }
	else { return "Ground and Air race. Distance: "; }
}

enum class Action
{
	Register_Transport = 1,
	Start_Race
};

void out_select_action_1(int& b)
{
	std::cout << "\nAt least 2 vehicles must be registered" << std::endl;
	std::cout << "1. Register a transport" << std::endl;
	do
	{
		std::cout << "Select an action: ";
		std::cin >> b;
	} while (b < 1 || b > 1);
}
void out_select_action_2(int& b)
{
	std::cout << std::endl;
	std::cout << "1. Register a transport" << std::endl;
	std::cout << "2. Start the race" << std::endl;
	do
	{
		std::cout << "Select an action: ";
		std::cin >> b;
	} while (b < 1 || b > 2);
}
void out_type_race_and_L(std::string type_race, double L)
{
	std::cout << "\n" << type_race << L << std::endl;
}
enum class Choosing_Vehicle	// ¬€¡Œ– “–¿Õ—œŒ–“ÕŒ√Œ —–≈ƒ—“¬¿
{
	Finish_registration,
	BootsTerrainVehicle,
	Broom,
	Camel,
	Centaur,
	Eagle,
	CamelFast,
	FlyingCarpet
};

void out_choosing_vehicle(int& c)
{
	std::cout << "1. Boots_Terrain_Vehicle" << std::endl;
	std::cout << "2. Broom" << std::endl;
	std::cout << "3. Camel" << std::endl;
	std::cout << "4. Centaur" << std::endl;
	std::cout << "5. Eagle" << std::endl;
	std::cout << "6. Camel_Fast" << std::endl;
	std::cout << "7. Flying_Carpet" << std::endl;
	std::cout << "0. Finish registration" << std::endl;
	do
	{
		std::cout << "Select transport or 0 to end the registration process: ";
		std::cin >> c;
	} while (c < 0 || c > 7);
}

void Continue_or_End_Game(int& a)
{
	std::cout << std::endl;
	std::cout << "1. To hold another race" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cout << "Select an action: ";
	int i;
	do {
		std::cin >> i;
	} while (i < 0 || i > 2);
	if (i == 2) { a = 0; }
}

void select_choosing_vehicle(std::string& type_race, double& L, int& b, int& c, int& n, Ground_Race** Group_racers, CamelFast& camel_fast, Camel& camel, BootsTerrainVehicle& boot_ter_veh, Centaur& cent)
{
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::BootsTerrainVehicle)
	{
		Group_racers[n] = &boot_ter_veh;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Camel)
	{
		Group_racers[n] = &camel;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Centaur)
	{
		Group_racers[n] = &cent;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::CamelFast)
	{
		Group_racers[n] = &camel_fast;
		++n;
	}
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::FlyingCarpet ||
		static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Broom ||
		static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Eagle)
	{
		std::cout << "\nAn attempt to register the wrong type of vehicle!" << std::endl;
	}
	else if (!(static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Finish_registration))
	{
		if (n == 1)
		{
			std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " successfully registered!" << std::endl;
		}
		else
		{
			int Double = 0;				//—◊≈“◊»  œŒ¬“Œ–ÕŒ√Œ ¬€¡Œ–¿ √ŒÕŸ» Œ¬
			for (int i = 0; i < (n - 1); i++)
			{
				if (Group_racers[i] == Group_racers[n - 1])
				{
					Double++;
				}
			}
			if (Double)
			{
				std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " already registered!" << std::endl;
				--n;
			}
			else
			{
				std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " successfully registered!" << std::endl;
			}
		}
	}
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Finish_registration)
	{
		if (n < 2) { out_select_action_1(b); c = 1; }
		else
		{
			out_select_action_2(b);
			if (b == 1) { c = 1; }
			else { c = 0; }
		}
	}
}

void print_Race_results(int n, int m, Ground_Race** Group_racers)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = n - 1; i > 0; i--)
			if (Group_racers[i]->get_time_race() < Group_racers[i - 1]->get_time_race())
			{
				Group_racers[m] = Group_racers[i];
				Group_racers[i] = Group_racers[i - 1];
				Group_racers[i - 1] = Group_racers[m];
			}
	}
	std::cout << "\nRace results:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ". " << Group_racers[i]->get_Out_Name() << ". Time: " << Group_racers[i]->get_time_race() << std::endl;
	}
	std::cout << std::endl;
}


void select_choosing_vehicle(std::string& type_race, double& L, int& b, int& c, int& n, Air_Race** Group_racers, Broom& broom, Eagle& eagle, FlyingCarpet& fly_car)
{
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::FlyingCarpet)
	{
		Group_racers[n] = &fly_car;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Broom)
	{
		Group_racers[n] = &broom;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Eagle)
	{
		Group_racers[n] = &eagle;
		++n;
	}
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::BootsTerrainVehicle ||
		static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Camel ||
		static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Centaur ||
		static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::CamelFast)
	{
		std::cout << "\nAn attempt to register the wrong type of vehicle!" << std::endl;
	}
	else if (!(static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Finish_registration))
	{
		if (n == 1)
		{
			std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " successfully registered!" << std::endl;
		}
		else
		{
			int Double = 0;				//—◊≈“◊»  œŒ¬“Œ–ÕŒ√Œ ¬€¡Œ–¿ √ŒÕŸ» Œ¬
			for (int i = 0; i < (n - 1); i++)
			{
				if (Group_racers[i] == Group_racers[n - 1])
				{
					Double++;
				}
			}
			if (Double)
			{
				std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " already registered!" << std::endl;
				--n;
			}
			else
			{
				std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " successfully registered!" << std::endl;
			}
		}
	}
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Finish_registration)
	{
		if (n < 2) { out_select_action_1(b); c = 1; }
		else
		{
			out_select_action_2(b);
			if (b == 1) { c = 1; }
			else { c = 0; }
		}
	}
}

void print_Race_results(int n, int m, Air_Race** Group_racers)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = n - 1; i > 0; i--)
			if (Group_racers[i]->get_time_race() < Group_racers[i - 1]->get_time_race())
			{
				Group_racers[m] = Group_racers[i];
				Group_racers[i] = Group_racers[i - 1];
				Group_racers[i - 1] = Group_racers[m];
			}
	}
	std::cout << "\nRace results:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ". " << Group_racers[i]->get_Out_Name() << ". Time: " << Group_racers[i]->get_time_race() << std::endl;
	}
	std::cout << std::endl;
}


void select_choosing_vehicle(std::string& type_race, double& L, int& b, int& c, int& n, Ground_and_Air_Race** Group_racers, Broom& broom, Eagle& eagle, FlyingCarpet& fly_car, CamelFast& camel_fast, Camel& camel, BootsTerrainVehicle& boot_ter_veh, Centaur& cent)
{
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::FlyingCarpet)
	{
		Group_racers[n] = &fly_car;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Broom)
	{
		Group_racers[n] = &broom;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Eagle)
	{
		Group_racers[n] = &eagle;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::BootsTerrainVehicle)
	{
		Group_racers[n] = &boot_ter_veh;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Camel)
	{
		Group_racers[n] = &camel;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Centaur)
	{
		Group_racers[n] = &cent;
		++n;
	}
	else if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::CamelFast)
	{
		Group_racers[n] = &camel_fast;
		++n;
	}
	if (!(static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Finish_registration))
	{
		if (n == 1)
		{
			std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " successfully registered!" << std::endl;
		}
		else
		{
			int Double = 0;				//—◊≈“◊»  œŒ¬“Œ–ÕŒ√Œ ¬€¡Œ–¿ √ŒÕŸ» Œ¬
			for (int i = 0; i < (n - 1); i++)
			{
				if (Group_racers[i] == Group_racers[n - 1])
				{
					Double++;
				}
			}
			if (Double)
			{
				std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " already registered!" << std::endl;
				--n;
			}
			else
			{
				std::cout << "\n" << Group_racers[n - 1]->get_Out_Name() << " successfully registered!" << std::endl;
			}
		}
	}
	if (static_cast<Choosing_Vehicle>(c) == Choosing_Vehicle::Finish_registration)
	{
		if (n < 2) { out_select_action_1(b); c = 1; }
		else
		{
			out_select_action_2(b);
			if (b == 1) { c = 1; }
			else { c = 0; }
		}
	}
}

void print_Race_results(int n, int m, Ground_and_Air_Race** Group_racers)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = n - 1; i > 0; i--)
			if (Group_racers[i]->get_time_race() < Group_racers[i - 1]->get_time_race())
			{
				Group_racers[m] = Group_racers[i];
				Group_racers[i] = Group_racers[i - 1];
				Group_racers[i - 1] = Group_racers[m];
			}
	}
	std::cout << "\nRace results:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ". " << Group_racers[i]->get_Out_Name() << ". Time: " << Group_racers[i]->get_time_race() << std::endl;
	}
	std::cout << std::endl;
}