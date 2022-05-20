# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)
project ("mario_project")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")
find_package (SFML 2.5 COMPONENTS audio graphics REQUIRED)
set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)
if (MSVC)
	add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()
add_executable (mario_project WIN32)
target_link_libraries (mario_project sfml-graphics sfml-audio sfml-main)
configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)
# Include sub-projects.
add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (Fonts)
add_subdirectory (Levels)
add_subdirectory (Sounds)
add_subdirectory (Textures)

