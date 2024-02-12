#pragma once
#include "Air_Race.h"
#include "Header_DLL.h"

	//  À¿——  Œ¬®– —¿ÃŒÀ®“

namespace my_space
{
	class FlyingCarpet : public Air_Race
	{
	protected:
		FlyingCarpet(double, int, std::string);
	public:
		RacingSimulator_Dll_API FlyingCarpet(double);
		RacingSimulator_Dll_API double get_time_race() override;
	};
}