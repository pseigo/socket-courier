cmake_minimum_required(VERSION 3.13..3.18)

project(socket_courier_cli
        VERSION 0.0.1
        DESCRIPTION "Cross-platform desktop client for testing WebSocket connections"
        HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
        LANGUAGES CXX)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# Compiler flags... a lot of ways of doing the same thing?
set_target_properties(${PROJECT_NAME} PROPERTIES
                      CXX_STANDARD 11)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
if (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

# Find libraries
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/lib")
find_package(ixwebsocket REQUIRED)

# Define executable target
include_directories(${websocketpp_INCLUDE_DIRS})
# add_library(websocket_client STATIC src/websocket_client/x.cpp src/websocket_client/x.h)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} websocket_client_LIBS ${_LIBS})

# not sure why this is necessary or what it does
# apparently installs our binary into the bin directory of the install directory
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
