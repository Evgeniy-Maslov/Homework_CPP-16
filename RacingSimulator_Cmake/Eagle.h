#pragma once
#include "Air_Race.h"
#include "Header_DLL.h"


	//  À¿—— Œ–®À

namespace my_space
{
	class Eagle : public Air_Race
	{
	protected:
		Eagle(double, int, std::string);
	public:
		RacingSimulator_Dll_API Eagle(double);
		RacingSimulator_Dll_API double get_time_race() override;
	};
}