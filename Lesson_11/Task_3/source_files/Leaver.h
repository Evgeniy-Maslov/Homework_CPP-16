#pragma once
#include<string>
#ifdef Dynam_Lib_EXPORTS
#define Dynam_Lib_API __declspec(dllexport)
#else
#define Dynam_Lib_API __declspec(dllimport)
#endif

namespace Dynam_Lib
{
	class Leaver
	{
	public:
		Dynam_Lib_API std::string Leave(std::string& a);
	};
}
