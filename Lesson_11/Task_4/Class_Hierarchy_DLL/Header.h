#pragma once

#ifdef DYNAMIC_LIBRARY_EXPORTS
#define DYNAMIC_LIBRARY_API __declspec(dllimport)
#else
#define DYNAMIC_LIBRARY_API __declspec(dllexport)
#endif