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

#define BIT(x) (1 << x)

