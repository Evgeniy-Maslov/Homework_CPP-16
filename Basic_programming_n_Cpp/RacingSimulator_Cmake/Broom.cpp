#include "Broom.h"	


	// ÊËÀÑÑ ÌÅÒËÀ

namespace my_space
{
	Broom::Broom(double Distance) : Broom(Distance, 20, "Broom") { }
	Broom::Broom(double Distance, int Speed, std::string Name_vehicle_racing) : Air_Race(Distance, Speed, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Name_vehicle_racing = Name_vehicle_racing;
		if (Distance / 1000 > 1)
		{
			Percent = static_cast<int>(Distance) / 1000;
		}
	}
	double Broom::get_time_race()
	{
		Air_Race::get_time_race();
		return T_race;
	}
}