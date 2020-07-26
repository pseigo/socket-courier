cmake_minimum_required(VERSION 3.18)

project(SocketCourierGui
  VERSION 0.0.1
  DESCRIPTION "Graphical WebSocket client"
  HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
  LANGUAGES CXX
)

### Code generation tools for Qt ###
# Meta-object code (moc) - generates .moc files if needed (for a target's C++ files)
set(CMAKE_AUTOMOC ON)

# Resource compiler (rcc) - virtual file system content generation (for a target's .qrc files)
set(CMAKE_AUTORCC ON)

# User Interface Compiler (uic) - widget layout and population (for .ui files used by C++ files in a target)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
  mainwindow.ui
  mainwindow.cpp
  main.cpp
  resources.qrc
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
