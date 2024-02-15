#include "Eagle.h"


	// Класс Орел

namespace my_space
{
	Eagle::Eagle(double Distance) : Eagle(Distance, 8, "Eagle") { }
	Eagle::Eagle(double Distance, int Speed, std::string Name_vehicle_racing) : Air_Race(Distance, Speed, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Name_vehicle_racing = Name_vehicle_racing;
		Percent = 6;

	}
	double Eagle::get_time_race()
	{
		Air_Race::get_time_race();
		return T_race;
	}
}