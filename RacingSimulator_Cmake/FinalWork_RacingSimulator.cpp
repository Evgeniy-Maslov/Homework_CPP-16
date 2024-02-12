#include "Air_Race.h"
#include "BootsTerrainVehicle.h"
#include "Broom.h"			
#include "Camel.h"
#include "CamelFast.h"
#include "Centaur.h"
#include "Eagle.h"
#include "FlyingCarpet.h"
#include "Ground_and_Air_Race.h"
#include "Ground_Race.h"
#include "Race.h"
#include <iostream>
#include "General_Functions.h"
#include "Header_DLL.h"




using namespace my_space;

int main(int argc, char** argv)
{
	int a = 1;					// СЧЕТЧИК ВЫБОРА ТИПА ГОНОК
	int b{};					// СЧЕТЧИК Select an action
	int c = 1;					// СЧЕТЧИК ВЫБОРА ТРАНСПОРТНОГО СРЕДСТВА
	double L;					// ВВОД ДИСТАНЦИИ
	std::string type_race;		// ВЫБОР ТИПА ГОНОК
	std::string vehicle;		// ВЫБОР ТРАНСПОРТНОГО СРЕДСТВА

	std::cout << "Welcome to the racing simulator!" << std::endl;
	while (a)
	{
		out_select_type_of_race(a);
		type_race = select_type_of_race(a);
		std::cout << "Specify the length of the distance (the length must be positive): ";
		std::cin >> L;
		Broom broom(L);
		Eagle eagle(L);
		FlyingCarpet fly_car(L);
		CamelFast camel_fast(L);
		Camel camel(L);
		BootsTerrainVehicle boot_ter_veh(L);
		Centaur cent(L);	
		if (a == 1)
		{
			int n = 0;				// СЧЕТЧИК ГОНЩИКОВ
			const int m = 5;
			Ground_Race** Group_racers = new Ground_Race* [m];
			out_select_action_1(b);
			while (b == 1)
			{
				while (c)
				{
					out_type_race_and_L(type_race, L);
					if (n)
					{
						std::cout << "Registered vehicles: ";
						for (int i = 0; i < n; i++)
						{
							if (i == 0) { std::cout << Group_racers[i]->get_Out_Name(); }
							else { std::cout << ", " << Group_racers[i]->get_Out_Name(); }
						}
						std::cout << std::endl;
					}
					out_choosing_vehicle(c);
					select_choosing_vehicle(type_race, L, b, c, n, Group_racers, camel_fast, camel, boot_ter_veh, cent);
				}
			}
			print_Race_results(n, m, Group_racers);
			c = 1;
		}
			
		else if (a == 2)
		{
			int n = 0;				// СЧЕТЧИК ГОНЩИКОВ
			int m = 4;
			Air_Race** Group_racers = new Air_Race * [m];
			out_select_action_1(b);
			while (b == 1)
			{
				while (c)
				{
					out_type_race_and_L(type_race, L);
					if (n)
					{
						std::cout << "Registered vehicles: ";
						for (int i = 0; i < n; i++)
						{
							if (i == 0) { std::cout << Group_racers[i]->get_Out_Name(); }
							else { std::cout << ", " << Group_racers[i]->get_Out_Name(); }
						}
						std::cout << std::endl;
					}
					out_choosing_vehicle(c);
					select_choosing_vehicle(type_race, L, b, c, n, Group_racers, broom, eagle, fly_car);
				}
			}
			print_Race_results(n, m, Group_racers);
			c = 1;
		}

		else
		{
			int n = 0;				// СЧЕТЧИК ГОНЩИКОВ
			int m = 8;
			Ground_and_Air_Race** Group_racers = new Ground_and_Air_Race * [m];
			out_select_action_1(b);
			while (b == 1)
			{
				while (c)
				{
					out_type_race_and_L(type_race, L);
					if (n)
					{
						std::cout << "Registered vehicles: ";
						for (int i = 0; i < n; i++)
						{
							if (i == 0) { std::cout << Group_racers[i]->get_Out_Name(); }
							else { std::cout << ", " << Group_racers[i]->get_Out_Name(); }
						}
						std::cout << std::endl;
					}
					out_choosing_vehicle(c);
					select_choosing_vehicle(type_race, L, b, c, n, Group_racers, broom, eagle, fly_car, camel_fast, camel, boot_ter_veh, cent);
				}
			}
			print_Race_results(n, m, Group_racers);
			c = 1;
		}
	Continue_or_End_Game(a);
	}
	return 0;
}