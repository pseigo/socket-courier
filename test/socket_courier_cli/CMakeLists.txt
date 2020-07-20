cmake_minimum_required(VERSION 3.13..3.18)

project(socket_courier_cli_test
        VERSION 0.0.1
        DESCRIPTION "Barebones command line WebSocket client"
        HOMEPAGE_URL "https://github.com/pseigo/socket-courier"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

# Also link my own libraries if I'm testing them
target_link_libraries(${PROJECT_NAME} PRIVATE doctest::doctest)

add_test(NAME FooTest COMMAND ${PROJECT_NAME})
