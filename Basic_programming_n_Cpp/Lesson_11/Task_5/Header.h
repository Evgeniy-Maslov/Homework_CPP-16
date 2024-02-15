#pragma once

#ifdef Class_Hierarchy_DLL_EXPORTS
#define Class_Hierarchy_DLL_API __declspec(dllexport)
#else
#define Class_Hierarchy_DLL_API __declspec(dllimport)
#endif