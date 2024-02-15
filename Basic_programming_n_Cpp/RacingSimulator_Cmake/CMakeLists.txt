cmake_minimum_required(VERSION 3.22.0)
project(FinalWork_RacingSimulator VERSION 0.1 LANGUAGES CXX) 
set(LIBRARY_NAME RacingSimulator_Dll)
set(SOURCES
Air_Race.cpp
BootsTerrainVehicle.cpp
Broom.cpp
Camel.cpp
CamelFast.cpp
Centaur.cpp
Eagle.cpp
FlyingCarpet.cpp
Ground_and_Air_Race.cpp
Ground_Race.cpp
Race.cpp)
set(HEADERS
Header_DLL.h
Air_Race.h
BootsTerrainVehicle.h
Broom.h
Camel.h
CamelFast.h
Centaur.h
Eagle.h
FlyingCarpet.h
Ground_and_Air_Race.h
Ground_Race.h
Race.h)
add_library( ${LIBRARY_NAME} SHARED ${SOURCES} ${HEADERS})
set(PROJECT_NAME RacingSimulator_Client)
add_executable(
${PROJECT_NAME}
FinalWork_RacingSimulator.cpp
General_Functions.cpp
General_Functions.h)
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})