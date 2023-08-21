project "DiligentCore"
   kind "StaticLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files
   {
    "include/**.hpp",
    "include/**.h"
   }

   includedirs
   {
       "include"
   }

   filter "system:Windows"
      systemversion "latest"
      staticruntime "on"

   filter {"system:Windows", "configurations:Release"}
      buildoptions "/MT"
