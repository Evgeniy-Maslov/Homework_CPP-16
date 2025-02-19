#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)

#имя проекта
project(Checking_functions_adding_and_receiving_elements)

#ищем библиотеку для подключения Catch2 из vcpkg
find_package(Catch2 CONFIG REQUIRED)

#добавляем поддиректорию, в которой будет catch2
#add_subdirectory(Catch2)

#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} 
unit_test.cpp
main.cpp)

#линкуемся к catch2, в котором уже есть main
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)