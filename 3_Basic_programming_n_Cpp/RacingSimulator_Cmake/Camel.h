#pragma once
#include "CamelFast.h"
#include "Header_DLL.h"

	// ÊËÀÑÑ ÂÅÐÁËÞÄ

namespace my_space
{
	class Camel : public CamelFast
	{
	protected:
		Camel(double, int, int, double, double, std::string);
	public:
		RacingSimulator_Dll_API Camel(double Distance);
		RacingSimulator_Dll_API double get_time_race() override;
	};
}
