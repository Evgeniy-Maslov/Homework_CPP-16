#pragma once
#include "Air_Race.h"
#include "Header_DLL.h"

	//  À¿—— Ã≈“À¿

namespace my_space
{
	class Broom : public Air_Race
	{
	protected:
		Broom(double, int, std::string);
	public:
		RacingSimulator_Dll_API Broom(double);
		RacingSimulator_Dll_API double get_time_race() override;
	};
}