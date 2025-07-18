cmake_minimum_required(VERSION 3.16)

project(Final_work_Airport_Inspector VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Concurrent )
find_package(Qt6 COMPONENTS PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS PrintSupport REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Final_work_Airport_Inspector
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        database.h database.cpp
        airportcongestion.h airportcongestion.cpp airportcongestion.ui
        qcustomplot.cpp
        qcustomplot.h




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Final_work_Airport_Inspector APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Final_work_Airport_Inspector SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Final_work_Airport_Inspector
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/PG_Libs)
target_link_libraries(Final_work_Airport_Inspector PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                                           Qt${QT_VERSION_MAJOR}::Sql
                                                           libcrypto-3-x64
                                                           libiconv-2
                                                           libintl-9
                                                           libpq
                                                           libssl-3-x64
                                                           Qt${QT_VERSION_MAJOR}::Concurrent
                                                           Qt${QT_VERSION_MAJOR}::PrintSupport
                                                           )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Final_work_Airport_Inspector)
endif()
set_target_properties(Final_work_Airport_Inspector PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Final_work_Airport_Inspector
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Final_work_Airport_Inspector)
endif()
