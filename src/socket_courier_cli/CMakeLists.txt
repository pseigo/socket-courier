cmake_minimum_required(VERSION 3.18)

project(SocketCourierCli
        VERSION 0.0.1
        DESCRIPTION "Barebones command line WebSocket client"
        HOMEPAGE_URL ${SOCKET_COURIER_HOMEPAGE_URL}
        LANGUAGES CXX)

###
### Define executable target
###
add_executable(${PROJECT_NAME} main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)

# Dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE WsClient::WsClient ixwebsocket)
