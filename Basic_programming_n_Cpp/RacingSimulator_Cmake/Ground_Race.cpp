#include "Ground_Race.h"



	// ÊËÀÑÑ ÍÀÇÅÌÍÀß ÃÎÍÊÀ

namespace my_space
{
	Ground_Race::Ground_Race() : Ground_Race(0, 0, 0, "Ground_Race") { }
	Ground_Race::Ground_Race(double Distance, int Speed, int Travel_time_to_rest, std::string Name_vehicle_racing) : Ground_and_Air_Race(Distance, Speed, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Travel_time_to_rest = Travel_time_to_rest;
		this->Name_vehicle_racing = Name_vehicle_racing;
	}
}