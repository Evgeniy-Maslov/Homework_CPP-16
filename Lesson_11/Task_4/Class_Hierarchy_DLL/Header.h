#pragma once

#ifdef CLASS_HIERARCHY_EXPORTS
	#define CLASS_HIERARCHY_API __declspec(dllimport)
#else
	#define CLASS_HIERARCHY_API __declspec(dllexport)
#endif