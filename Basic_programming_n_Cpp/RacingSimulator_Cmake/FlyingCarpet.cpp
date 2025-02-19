#include "FlyingCarpet.h"



	// ÊËÀÑÑ ÊÎÂ¨Ð ÑÀÌÎË¨Ò

namespace my_space
{
	FlyingCarpet::FlyingCarpet(double Distance) : FlyingCarpet(Distance, 10, "Flying_Carpet") { }
	FlyingCarpet::FlyingCarpet(double Distance, int Speed, std::string Name_vehicle_racing) : Air_Race(Distance, Speed, Name_vehicle_racing)
	{
		this->Speed = Speed;
		this->Name_vehicle_racing = Name_vehicle_racing;
		if (Distance >= 1000 && Distance < 5000) Percent = 3;
		if (Distance >= 5000 && Distance < 10000) Percent = 10;
		if (Distance >= 10000) Percent = 5;
	}
	double FlyingCarpet::get_time_race()
	{
		Air_Race::get_time_race();
		return T_race;
	}
}