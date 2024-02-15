#include "Air_Race.h"


	// ÊËÀÑÑ ÂÎÇÄÓØÍÀß ÃÎÍÊÀ

namespace my_space
{
	Air_Race::Air_Race() : Air_Race(0, 0, "Air_Race") { }

	Air_Race::Air_Race(double Distance, int Speed, std::string Name_vehicle_racing) : Ground_and_Air_Race(Distance, Speed, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Name_vehicle_racing = Name_vehicle_racing;
	}
	double Air_Race::get_time_race()
	{
		T_race = T_race_without_rest * (1 - Percent * 0.01);
		return T_race;
	}
}