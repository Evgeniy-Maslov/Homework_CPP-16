#pragma once
#include<string>
#ifdef Dynamic_Library_EXPORTS
#define Dynamic_Library_API __declspec(dllexport)
#else
#define Dynamic_Library_API __declspec(dllimport)
#endif

namespace Dynam_Lib
{
	class Leaver
	{
	public:
		Dynamic_Library_API std::string Leave(std::string& a);
	};
}