cmake_minimum_required(VERSION 3.22.0)
project(CMake_Class_hierarchy VERSION 0.1 LANGUAGES CXX) 
set(LIBRARY_NAME Class_Hierarchy_DLL)
set(SOURCES
Figure.cpp
Equilateral_triangle.cpp
Isosceles_triangle.cpp
Parallelogram.cpp
Quadrat.cpp
Quadrilateral.cpp
Rectangle.cpp
Rhomb.cpp
Right_angled_triangle.cpp
Triangle.cpp)
set(HEADERS
Header.h
Figure.h
Equilateral_triangle.h
Isosceles_triangle.h
Parallelogram.h
Quadrat.h
Quadrilateral.h
Rectangle.h
Rhomb.h
Right_angled_triangle.h
Triangle.h)
add_library( ${LIBRARY_NAME} SHARED ${SOURCES} ${HEADERS})
set(PROJECT_NAME Class_Hierarchy_Client)
set(SOURCES_C ConsoleAppClient.cpp)
add_executable(${PROJECT_NAME} ${SOURCES_C})
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})