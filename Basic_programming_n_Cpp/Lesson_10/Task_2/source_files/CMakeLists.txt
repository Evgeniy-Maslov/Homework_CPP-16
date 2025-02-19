cmake_minimum_required(VERSION 3.22.0)
project(Class_hierarchy_project VERSION 0.1 LANGUAGES CXX)
set(SOURCES 
Class_hierarchy.cpp
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
set(PROJECT_NAME Class_hierarchy_program)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})