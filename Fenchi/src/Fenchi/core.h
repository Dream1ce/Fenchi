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

#ifdef FC_ENABLE_ASSERTS
	#define FC_ASSERT(x,...){if(!(x)){FC_ERROR("Assertion Failed:{0}",__VA_ARGS);__debugbreak();}}
	#define FC_CORE_ASSERT(x,...){if(!(x)){FC_CORE_ERROR("Assertion Failed:{0}",__VA_ARGS);__debugbreak();}}
#else
	#define FC_ASSERT(x,...)
	#define FC_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1<<x)