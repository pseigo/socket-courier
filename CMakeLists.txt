cmake_minimum_required(VERSION 3.18)

project(SocketCourier
        VERSION 0.0.1
        DESCRIPTION "Cross-platform desktop client for testing WebSocket connections"
        HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
        LANGUAGES CXX)

# Public header files
set(SOCKETCOURIER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/socket_courier)

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# Only run if this is the main project (i.e., not added via add_subdirectory)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF) # Ensure -std=c++xx instead of -std=g++xx

  # Support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)
endif()

###
### Dependencies: Download and make available
###
include(FetchContent)
FetchContent_Declare(
  ixwebsocket
  GIT_REPOSITORY https://github.com/machinezone/IXWebSocket.git
  GIT_TAG        v9.9.0
)
FetchContent_MakeAvailable(ixwebsocket)
# adds ixwebsocket

FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  GIT_TAG        2.4.0
)
FetchContent_MakeAvailable(doctest)
# adds doctest::doctest

###
### Projects
###
add_subdirectory(src/ws_client)
add_subdirectory(src/socket_courier_cli)

###
### Test suite
###
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(test/ws_client)
endif()
