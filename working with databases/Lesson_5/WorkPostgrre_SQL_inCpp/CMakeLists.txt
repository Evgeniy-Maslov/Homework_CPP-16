cmake_minimum_required(VERSION 3.20)
project(WorkPostgrre_SQL_inCpp)
add_executable(${PROJECT_NAME} 
main.cpp
ClientManagement.cpp 
ClientManagement.h
)
add_subdirectory("D:/source/libpqxx-7.7.4" libpqxx-build)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} pqxx)