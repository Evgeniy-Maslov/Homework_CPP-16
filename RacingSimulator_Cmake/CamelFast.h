#pragma once
#include "Ground_Race.h"
#include "Header_DLL.h"

	// ����� ������� - ��������

namespace my_space
{
	class CamelFast : public Ground_Race
	{
	protected:
		double Time_relax;			// ������������ ������
		double Time_relax_2;		// ������������ ������ 2
		double Time_relax_3;		// ������������ ������ 3
		CamelFast(double, int, int, double, double, double, std::string);
	public:
		RacingSimulator_Dll_API CamelFast(double);
		RacingSimulator_Dll_API double get_time_race() override;
	};
}