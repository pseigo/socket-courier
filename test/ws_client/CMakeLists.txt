cmake_minimum_required(VERSION 3.18)

project(WsClientTest
        VERSION 0.0.1
        DESCRIPTION "Barebones command line WebSocket client"
        HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

# TODO: Also link my own libraries if I'm testing them
target_link_libraries(${PROJECT_NAME} PRIVATE doctest::doctest)

get_property(DOCTEST_INCLUDE_DIR
             TARGET doctest::doctest
             PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(${PROJECT_NAME} PRIVATE ${DOCTEST_INCLUDE_DIR}doctest)

add_test(NAME FooTest COMMAND ${PROJECT_NAME})
