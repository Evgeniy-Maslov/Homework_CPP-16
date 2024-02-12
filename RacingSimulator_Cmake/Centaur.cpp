#include "Centaur.h"


	// ÊËÀÑÑ ÊÅÍÒÀÂÐ

namespace my_space
{
	Centaur::Centaur(double Distance) : Centaur(Distance, 15, 8, 2, "Centaur") { }
	Centaur::Centaur(double Distance, int Speed, int Travel_time_to_rest, double Time_relax, std::string Name_vehicle_racing)
		: BootsTerrainVehicle(Distance, Speed, Travel_time_to_rest, Time_relax, Time_relax, Name_vehicle_racing)
	{

		this->Speed = Speed;
		this->Travel_time_to_rest = Travel_time_to_rest;
		this->Time_relax = Time_relax;
		this->Name_vehicle_racing = Name_vehicle_racing;
	}
	double Centaur::get_time_race()
	{
		CamelFast::get_time_race();
		return T_race;
	}
}