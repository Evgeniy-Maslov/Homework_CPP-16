#pragma once
#include "Ground_and_Air_Race.h"
#include <string>
#include "Header_DLL.h"


	// йкюяя мюгелмюъ цнмйю

namespace my_space
{
	class Ground_Race : public Ground_and_Air_Race
	{
	protected:
		int Travel_time_to_rest;	// бпелъ дбхфемхъ дн нрдшую
		int Rest_stops;				// йнккхвеярбн нярюмнбнй дкъ нрдшую
		double T_relax_race;		// бпелъ нрдшую гю бяч цнмйс
		Ground_Race(double, int, int, std::string);
	public:
		RacingSimulator_Dll_API Ground_Race();
	};
}