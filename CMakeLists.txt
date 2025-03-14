cmake_minimum_required(VERSION 3.10)

project(ShortestPathFinder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ShortestPathFinder src/main.cpp src/Graph.cpp)
