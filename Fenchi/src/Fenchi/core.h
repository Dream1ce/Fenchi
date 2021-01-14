#pragma once


#ifdef FENCHI_PLATFORM_WINDOWS
	#ifdef FENCHI_BUILD_DLL
		#define FENCHI_API __declspec(dllexport)	
	#else
		#define FENCHI_API __declspec(dllimport)
	#endif
#else
	#error Finchi only on Windows!
#endif // To make the usage of dll more convient

