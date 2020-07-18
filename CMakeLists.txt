cmake_minimum_required(VERSION 3.13..3.18)

project(socket_courier
        VERSION 0.0.1
        DESCRIPTION "Cross-platform desktop client for testing WebSocket connections"
        HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
        LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

add_subdirectory(src/socket_courier_cli)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(test)
endif()
