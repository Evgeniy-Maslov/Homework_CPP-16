#pragma once
#include "Ground_and_Air_Race.h"
#include <string>
#include "Header_DLL.h"


	// ����� �������� �����

namespace my_space
{
	class Ground_Race : public Ground_and_Air_Race
	{
	protected:
		int Travel_time_to_rest;	// ����� �������� �� ������
		int Rest_stops;				// ����������� ��������� ��� ������
		double T_relax_race;		// ����� ������ �� ��� �����
		Ground_Race(double, int, int, std::string);
	public:
		RacingSimulator_Dll_API Ground_Race();
	};
}