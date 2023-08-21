workspace "LegendCreator"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["DiligentCore"] = "LegendCreator/vendor/DiligentCore/include"

include "LegendCreator/vendor/DiligentCore"

project "LegendCreator"
	location "LegendCreator"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lcpch.h"
	pchsource "LegendCreator/src/lcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.DiligentCore}"
	}

	links
	{
		"DiligentCore"
	}

	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LC_PLATFORM_WINDOWS",
			"LC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LC_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LC_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"LegendCreator/vendor/spdlog/include",
		"LegendCreator/src"
	}

	links
	{
		"LegendCreator"
	}

	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LC_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "LC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LC_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LC_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"