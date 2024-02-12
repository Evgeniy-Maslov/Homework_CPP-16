#pragma once
#include "BootsTerrainVehicle.h"
#include "Header_DLL.h"

	//  À¿——  ≈Õ“¿¬–

namespace my_space
{
	class Centaur : public BootsTerrainVehicle
	{
	protected:
		Centaur(double, int, int, double, std::string);
	public:
		RacingSimulator_Dll_API Centaur(double);
		RacingSimulator_Dll_API double get_time_race() override;
	};
}