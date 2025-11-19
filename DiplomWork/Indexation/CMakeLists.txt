cmake_minimum_required(VERSION 3.16)

project(Indexation LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Sql)

add_executable(Indexation
  main.cpp
  database.h database.cpp
  catalog.h catalog.cpp
  ../ParametersIndexing.ini ../SettingsPostgreSQL.ini

)

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/PG_Libs)
target_link_libraries(Indexation PRIVATE Qt${QT_VERSION_MAJOR}::Core
                                         Qt::Sql
                                         libcrypto-3-x64
                                         libiconv-2
                                         libintl-9
                                         libpq
                                         libssl-3-x64)

include(GNUInstallDirs)
install(TARGETS Indexation
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}S
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

