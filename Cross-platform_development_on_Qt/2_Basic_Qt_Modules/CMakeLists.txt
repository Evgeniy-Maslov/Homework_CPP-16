cmake_minimum_required(VERSION 3.16)

project(2_Basic_Qt_Modules LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Network)
find_package(Qt6 REQUIRED COMPONENTS Sql)

add_executable(2_Basic_Qt_Modules
  main.cpp
)

target_link_libraries(2_Basic_Qt_Modules
    PRIVATE Qt${QT_VERSION_MAJOR}::Core
    PRIVATE Qt6::Network
    PRIVATE Qt6::Sql)

include(GNUInstallDirs)
install(TARGETS 2_Basic_Qt_Modules
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

