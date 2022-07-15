cmake_minimum_required(VERSION 3.5)

project(Spectry VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/Include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/Source)

file( GLOB HEADERS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp" )
file( GLOB SOURCES "${SRC_DIR}/*.c" "${SRC_DIR}/*.cpp" )
file( GLOB FORMS "${SRC_DIR}/*.ui" )

source_group("Ui" FILES ${FORMS})
include_directories(${INCLUDE_DIR})


###This place will be optimized in the future###

#Widgets {
    #LoadingWidget
    set(PATH_LoadingWidget ${CMAKE_SOURCE_DIR}/Widgets/LoadingWidget)
    file( GLOB LoadingWidget
        "${PATH_LoadingWidget}/*.h"
        "${PATH_LoadingWidget}/*.hpp"
        "${PATH_LoadingWidget}/*.c"
        "${PATH_LoadingWidget}/*.cpp"
        "${PATH_LoadingWidget}/*.ui"
    )
    source_group("LoadingWidget" FILES ${LoadingWidget})
    include_directories(${PATH_LoadingWidget})

    #GreetingWidget
    set(PATH_GreetingWidget ${CMAKE_SOURCE_DIR}/Widgets/GreetingWidget)
    file( GLOB GreetingWidget
        "${PATH_GreetingWidget}/*.h"
        "${PATH_GreetingWidget}/*.hpp"
        "${PATH_GreetingWidget}/*.c"
        "${PATH_GreetingWidget}/*.cpp"
        "${PATH_GreetingWidget}/*.ui"
    )
    source_group("GreetingWidget" FILES ${GreetingWidget})
    include_directories(${PATH_GreetingWidget})

    #NadyaDialog1Widget
    set(PATH_NadyaDialog1Widget ${CMAKE_SOURCE_DIR}/Widgets/NadyaDialog1Widget)
    file( GLOB NadyaDialog1Widget
        "${PATH_NadyaDialog1Widget}/*.h"
        "${PATH_NadyaDialog1Widget}/*.hpp"
        "${PATH_NadyaDialog1Widget}/*.c"
        "${PATH_NadyaDialog1Widget}/*.cpp"
        "${PATH_NadyaDialog1Widget}/*.ui"
    )
    source_group("NadyaDialog1Widget" FILES ${NadyaDialog1Widget})
    include_directories(${PATH_NadyaDialog1Widget})

    #NadyaDialog2Widget
    set(PATH_NadyaDialog2Widget ${CMAKE_SOURCE_DIR}/Widgets/NadyaDialog2Widget)
    file( GLOB NadyaDialog2Widget
        "${PATH_NadyaDialog2Widget}/*.h"
        "${PATH_NadyaDialog2Widget}/*.hpp"
        "${PATH_NadyaDialog2Widget}/*.c"
        "${PATH_NadyaDialog2Widget}/*.cpp"
        "${PATH_NadyaDialog2Widget}/*.ui"
    )
    source_group("NadyaDialog2Widget" FILES ${NadyaDialog2Widget})
    include_directories(${PATH_NadyaDialog2Widget})

    #MainMenuWidget
    set(PATH_MainMenuWidget ${CMAKE_SOURCE_DIR}/Widgets/MainMenuWidget)
    file( GLOB MainMenuWidget
        "${PATH_MainMenuWidget}/*.h"
        "${PATH_MainMenuWidget}/*.hpp"
        "${PATH_MainMenuWidget}/*.c"
        "${PATH_MainMenuWidget}/*.cpp"
        "${PATH_MainMenuWidget}/*.ui"
    )
    source_group("MainMenuWidget" FILES ${MainMenuWidget})
    include_directories(${PATH_MainMenuWidget})

    #BookTextWidget
    set(PATH_BookTextWidget ${CMAKE_SOURCE_DIR}/Widgets/BookTextWidget)
    file( GLOB BookTextWidget
        "${PATH_BookTextWidget}/*.h"
        "${PATH_BookTextWidget}/*.hpp"
        "${PATH_BookTextWidget}/*.c"
        "${PATH_BookTextWidget}/*.cpp"
        "${PATH_BookTextWidget}/*.ui"
    )
    source_group("BookTextWidget" FILES ${BookTextWidget})
    include_directories(${PATH_BookTextWidget})

    #PurposesMenuInfoWidget
    set(PATH_PurposesMenuInfoWidget ${CMAKE_SOURCE_DIR}/Widgets/PurposesMenuInfoWidget)
    file( GLOB PurposesMenuInfoWidget
        "${PATH_PurposesMenuInfoWidget}/*.h"
        "${PATH_PurposesMenuInfoWidget}/*.hpp"
        "${PATH_PurposesMenuInfoWidget}/*.c"
        "${PATH_PurposesMenuInfoWidget}/*.cpp"
        "${PATH_PurposesMenuInfoWidget}/*.ui"
    )
    source_group("PurposesMenuInfoWidget" FILES ${PurposesMenuInfoWidget})
    include_directories(${PATH_PurposesMenuInfoWidget})

    #PurposesMenuWidget
    set(PATH_PurposesMenuWidget ${CMAKE_SOURCE_DIR}/Widgets/PurposesMenuWidget)
    file( GLOB PurposesMenuWidget
        "${PATH_PurposesMenuWidget}/*.h"
        "${PATH_PurposesMenuWidget}/*.hpp"
        "${PATH_PurposesMenuWidget}/*.c"
        "${PATH_PurposesMenuWidget}/*.cpp"
        "${PATH_PurposesMenuWidget}/*.ui"
    )
    source_group("PurposesMenuWidget" FILES ${PurposesMenuWidget})
    include_directories(${PATH_PurposesMenuWidget})


    set(WidgetSources
        ${LoadingWidget}
        ${GreetingWidget}
        ${NadyaDialog1Widget}
        ${NadyaDialog2Widget}
        ${MainMenuWidget}
        ${BookTextWidget}
        ${PurposesMenuWidget}
        ${PurposesMenuInfoWidget}
    )
#Widgets }


set(PROJECT_SOURCES
        ${HEADERS} ${SOURCES} ${FORMS} ${WidgetSources} ResourceConfig.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Spectry
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Vector-cpp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Spectry SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Spectry
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Spectry PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Spectry PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Spectry)
endif()
