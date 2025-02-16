#pragma once
#include "Race.h"
#include "Header_DLL.h"

	// ����� �������������� �����

namespace my_space
{
	class Ground_and_Air_Race : public Race
	{
	protected:
		int Speed;					// �������� ��������
		double T_race_without_rest;	// ����� ����� ��� ������
		Ground_and_Air_Race(double, int, std::string);
	public:
		RacingSimulator_Dll_API Ground_and_Air_Race();
		RacingSimulator_Dll_API virtual double get_time_race();
		RacingSimulator_Dll_API std::string get_Out_Name();
	};
}