cmake_minimum_required(VERSION 3.20)

project(UDP_Server)

#set (CMAKE_CXX_STANDARD 17)
#or 
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(${PROJECT_NAME} UServer.cpp main.cpp)



