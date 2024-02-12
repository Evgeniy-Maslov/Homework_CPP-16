#include "Race.h"



	// ÊËÀÑÑ ÃÎÍÊÀ

namespace my_space
{
	Race::Race() :Race(0.0) { }
	Race::Race(double Distance)
	{
		this->Distance = Distance;
	}
	double Race::get_Out_Distance() { return Distance; }
}