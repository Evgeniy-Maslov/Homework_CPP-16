#pragma once
#include <iostream>
#include "Header_DLL.h"

	// ÊËÀÑÑ ÃÎÍÊÀ

namespace my_space
{
	class Race
	{
	protected:
		Race(double Distance);
		std::string Name_vehicle_racing;	// ÍÀÇÂÀÍÈÅ ÒĞÀÍÑÏÎĞÒÍÎÃÎ ÑĞÅÄÑÒÂÀ
		double Distance;					// ÄÈÑÒÀÍÖÈß
		double T_race;						// ÂĞÅÌß ÃÎÍÊÈ (ÈÒÎÃÎÂÎÅ)
	public:
		RacingSimulator_Dll_API Race();
		double get_Out_Distance();

	};
}