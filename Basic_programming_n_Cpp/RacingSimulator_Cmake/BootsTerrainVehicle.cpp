#include "BootsTerrainVehicle.h"


	// ÊËÀÑÑ ÁÎÒÈÍÊÈ - ÂÅÇÄÅÕÎÄÛ

namespace my_space
{
	BootsTerrainVehicle::BootsTerrainVehicle(double Distance) : BootsTerrainVehicle(Distance, 6, 60, 10, 5, "Boots_Terrain_Vehicle") { }
	BootsTerrainVehicle::BootsTerrainVehicle(double Distance, int Speed, int Travel_time_to_rest, double Time_relax, double Time_relax_2, std::string Name_vehicle_racing)
		: CamelFast(Distance, Speed, Travel_time_to_rest, Time_relax, Time_relax_2, Time_relax_2, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Travel_time_to_rest = Travel_time_to_rest;
		this->Time_relax = Time_relax;
		this->Time_relax_2 = Time_relax_2;
		this->Name_vehicle_racing = Name_vehicle_racing;
	}
	double BootsTerrainVehicle::get_time_race()
	{
		CamelFast::get_time_race();
		return T_race;
	}
}