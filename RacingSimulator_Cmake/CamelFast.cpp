#include "CamelFast.h"



	// ÊËÀÑÑ ÂÅÐÁËÞÄ - ÁÛÑÒÐÎÕÄ

namespace my_space
{
	CamelFast::CamelFast(double Distance) : CamelFast(Distance, 40, 10, 5, 6.5, 8, "Camel_Fast") { }
	CamelFast::CamelFast(double Distance, int Speed, int Travel_time_to_rest, double Time_relax, double Time_relax_2, double Time_relax_3, std::string Name_vehicle_racing)
		: Ground_Race(Distance, Speed, Travel_time_to_rest, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Travel_time_to_rest = Travel_time_to_rest;
		this->Time_relax = Time_relax;
		this->Time_relax_2 = Time_relax_2;
		this->Time_relax_3 = Time_relax_3;
		this->Name_vehicle_racing = Name_vehicle_racing;
	}
	double CamelFast::get_time_race()
	{
		if (static_cast<int>(T_race_without_rest) % Travel_time_to_rest)
		{
			Rest_stops = static_cast<int>(T_race_without_rest) / Travel_time_to_rest;
		}
		else
		{
			Rest_stops = static_cast<int>(T_race_without_rest) / Travel_time_to_rest - 1;
		}
		if (Rest_stops == 1)
		{
			Time_relax_2 = Time_relax_3 = 0;
		}
		else if (Rest_stops == 2)
		{
			Time_relax_3 = 0;
		}
		T_race = T_race_without_rest + Time_relax + Time_relax_2 + (Rest_stops - 2) * Time_relax_3;
		return T_race;
	}
}