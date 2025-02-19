#минимальная версия cmake
cmake_minimum_required(VERSION 3.11)

#имя проекта
project(Checking_basic_functions_doubly_list)

#ищем библиотеку для подключения Catch2 из vcpkg
find_package(Catch2 CONFIG REQUIRED)

#добавляем поддиректорию, в которой будет catch2
#add_subdirectory(catch2)

#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} main.cpp)

#линкуемся к catch2, в котором уже есть main
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)