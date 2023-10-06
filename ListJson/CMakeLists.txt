# CMakeList.txt: proyecto de CMake para ListJson, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (ListJson "ListJson.cpp" "ListJson.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ListJson PROPERTY CXX_STANDARD 20)
endif()
