workspace "Fenchi"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Fenchi/vendor/GLFW/include"

include "Fenchi/vendor/GLFW"

project "Fenchi"
	location "Fenchi"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "fcpch.h"
	pchsource "Fenchi/src/fcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "ON"
		systemversion "latest"

		defines
		{
			"FENCHI_PLATFORM_WINDOWS","FENCHI_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")--这里的Sandbox的名字也要跟这具体项目名字改
		}
	filter "configurations:Debug"
		defines "FC_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "FC_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "FC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Fenchi/vendor/spdlog/include",
		"Fenchi/src"
	}

	links
	{
		"Fenchi"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "ON"
		systemversion "latest"

		defines
		{
			"FENCHI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FC_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "FC_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "FC_DIST"
		optimize "On"