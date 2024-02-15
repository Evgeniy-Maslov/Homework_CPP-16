#pragma once

#ifdef RacingSimulator_Dll_EXPORTS
#define RacingSimulator_Dll_API __declspec(dllexport)
#else
#define RacingSimulator_Dll_API __declspec(dllimport)
#endif
