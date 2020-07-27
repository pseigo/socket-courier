cmake_minimum_required(VERSION 3.17)

project(SocketCourierGui
  VERSION 0.0.1
  DESCRIPTION "Graphical WebSocket client"
  HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
  LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

### Code generation tools for Qt ###
# Meta-object code (moc) - generates .moc files if needed (for a target's C++ files)
set(CMAKE_AUTOMOC ON)

# Resource compiler (rcc) - virtual file system content generation (for a target's .qrc files)
set(CMAKE_AUTORCC ON)

# User Interface Compiler (uic) - widget layout and population (for .ui files used by C++ files in a target)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(SOURCE_FILES main.cpp mainwindow.cpp)
set(HEADER_FILES mainwindow.h)
set(UI_FILES mainwindow.ui)
set(TS_FILES ${PROJECT_NAME}_en_US.ts)

if(ANDROID)
  add_library(${PROJECT_NAME} SHARED
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
    ${TS_FILES}
  )
else()
  add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
    ${TS_FILES}
  )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
