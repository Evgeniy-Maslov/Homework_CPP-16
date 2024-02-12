#pragma once
#include "Ground_and_Air_Race.h"
#include "Header_DLL.h"

	//  À¿—— ¬Œ«ƒ”ÿÕ¿ﬂ √ŒÕ ¿

namespace my_space
{
	class Air_Race : public Ground_and_Air_Race
	{
	protected:
		int Percent = 1;				// œ–Œ÷≈Õ“ —Œ –¿Ÿ≈Õ»ﬂ –¿—“ŒﬂÕ»ﬂ
		Air_Race(double, int, std::string);
	public:
		RacingSimulator_Dll_API Air_Race();
		RacingSimulator_Dll_API double get_time_race() override;
	};
}