#include "Ground_and_Air_Race.h"
#include <iostream>



	// ÊËÀÑÑ ÊÎÌÁÎÍÈÐÎÂÀÍÀß ÃÎÍÊÀ	

namespace my_space
{
	Ground_and_Air_Race::Ground_and_Air_Race() : Ground_and_Air_Race(0, 0, "Ground_and_Air_Race") {}
	Ground_and_Air_Race::Ground_and_Air_Race(double Distance, int Speed, std::string Name_vehicle_racing) : Race(Distance)
	{
		this->Speed = Speed;
		this->Name_vehicle_racing = Name_vehicle_racing;
		T_race_without_rest = Distance / Speed;
	}
	double Ground_and_Air_Race::get_time_race() { return T_race; }
	std::string Ground_and_Air_Race::get_Out_Name() { return Name_vehicle_racing; }
}