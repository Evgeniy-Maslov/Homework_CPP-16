#pragma once
#include "CamelFast.h"
#include "Header_DLL.h"

	// йкюяя анрхмйх - бегдеундш

namespace my_space
{
	class BootsTerrainVehicle : public CamelFast
	{
	protected:
		BootsTerrainVehicle(double, int, int, double, double, std::string);
	public:
		RacingSimulator_Dll_API BootsTerrainVehicle(double Distance);
		RacingSimulator_Dll_API double get_time_race() override;
	};
}