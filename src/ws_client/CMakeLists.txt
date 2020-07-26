cmake_minimum_required(VERSION 3.18)

project(WsClient
  VERSION 0.0.1
  DESCRIPTION "A wrapper around IXWebSocket"
  HOMEPAGE_URL ${SOCKET_COURIER_HOMEPAGE_URL}
  LANGUAGES CXX
)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

###
### Variables
###
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/connection.cpp)
set(HEADER_FILES ${SOCKETCOURIER_INCLUDE_DIR}/connection.hpp)

###
### Define library target
###
add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${SOCKETCOURIER_INCLUDE_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)

# Dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE ixwebsocket)
