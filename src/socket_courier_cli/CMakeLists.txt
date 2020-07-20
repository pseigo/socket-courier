cmake_minimum_required(VERSION 3.13..3.18)

project(socket_courier_cli
        VERSION 0.0.1
        DESCRIPTION "Barebones command line WebSocket client"
        HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
        LANGUAGES CXX)

# Find libraries
# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extern")
# find_package(IXWebSocket REQUIRED)

# Define executable target
include_directories(${websocketpp_INCLUDE_DIRS})
# add_library(websocket_client STATIC src/websocket_client/x.cpp src/websocket_client/x.h)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ixwebsocket)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/_deps/ixwebsocket-build/ixwebsocket.dir/ixwebsocket")

# Compiler flags... a lot of ways of doing the same thing?
# set_target_properties(${PROJECT_NAME} PROPERTIES
#                       CXX_STANDARD 11)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
# if (UNIX)
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
# endif()
# set(CMAKE_CXX_STANDARD 11)

# not sure why this is necessary or what it does
# apparently installs our binary into the bin directory of the install directory
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
