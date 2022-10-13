cmake_minimum_required(VERSION 3.5)

project(FolderControl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        interface.cpp
        interface.h
        interface.ui
        view/tab.cpp
        view/tab.h
        view/window.cpp
        view/window.h
        view/duplicatefile/duplicatefile.cpp
        view/duplicatefile/duplicatefile.h
        view/emptyfolder/emptyfolder.cpp
        view/emptyfolder/emptyfolder.h
        view/textfolder/textfolder.cpp
        view/textfolder/textfolder.h
        view/removejunk/removejunk.cpp
        view/removejunk/removejunk.h
        view/about/about.cpp
        view/about/about.h
        view/about/aboutqt.cpp
        view/about/aboutqt.h
        res.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FolderControl
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FolderControl APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FolderControl SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FolderControl
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FolderControl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(FolderControl PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FolderControl)
endif()
