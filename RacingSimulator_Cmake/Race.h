#pragma once
#include <iostream>
#include "Header_DLL.h"

	// ����� �����

namespace my_space
{
	class Race
	{
	protected:
		Race(double Distance);
		std::string Name_vehicle_racing;	// �������� ������������� ��������
		double Distance;					// ���������
		double T_race;						// ����� ����� (��������)
	public:
		RacingSimulator_Dll_API Race();
		double get_Out_Distance();

	};
}