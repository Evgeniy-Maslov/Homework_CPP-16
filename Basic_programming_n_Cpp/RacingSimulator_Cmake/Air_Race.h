#pragma once
#include "Ground_and_Air_Race.h"
#include "Header_DLL.h"

	// ����� ��������� �����

namespace my_space
{
	class Air_Race : public Ground_and_Air_Race
	{
	protected:
		int Percent = 1;				// ������� ���������� ���������
		Air_Race(double, int, std::string);
	public:
		RacingSimulator_Dll_API Air_Race();
		RacingSimulator_Dll_API double get_time_race() override;
	};
}