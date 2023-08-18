#pragma once

#ifdef LC_PLATFORM_WINDOWS
	#ifdef LC_BUILD_DLL
		#define LEGENDCREATOR_API _declspec(dllexport)
	#else
		#define LEGENDCREATOR_API _declspec(dllimport)
	#endif
#else
	#error Legend Creator only supports Windows!
#endif

#ifdef LC_ENABLE_ASSERTS
	#define LC_ASSERT(x, ...) { if(!(x)) { LC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LC_CORE_ASSERT(x, ...) { if(!(x)) { LC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LC_ASSERT(x, ...)
	#define LC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

