#include "Camel.h"


	// ÊËÀÑÑ ÂÅÐÁËÞÄ

namespace my_space
{
	Camel::Camel(double Distance) : Camel(Distance, 10, 30, 5, 8, "Camel") { }
	Camel::Camel(double Distance, int Speed, int Travel_time_to_rest, double Time_relax, double Time_relax_2, std::string Name_vehicle_racing)
		: CamelFast(Distance, Speed, Travel_time_to_rest, Time_relax, Time_relax_2, Time_relax_2, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Travel_time_to_rest = Travel_time_to_rest;
		this->Time_relax = Time_relax;
		this->Time_relax_2 = Time_relax_2;
		this->Name_vehicle_racing = Name_vehicle_racing;
	}
	double Camel::get_time_race()
	{
		CamelFast::get_time_race();
		return T_race;
	}
}