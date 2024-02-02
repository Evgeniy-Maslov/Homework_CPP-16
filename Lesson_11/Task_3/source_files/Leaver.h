#pragma once
#include<string>
#ifdef DYNAMIC_LIBRARY_EXPORTS
#define DYNAMIC_LIBRARY_API __declspec(dllimport)
#else
#define DYNAMIC_LIBRARY_API __declspec(dllexport)
#endif

namespace Dynam_Lib
{
	class Leaver
	{
	public:
		DYNAMIC_LIBRARY_API std::string Leave(std::string& a);
	};
}
