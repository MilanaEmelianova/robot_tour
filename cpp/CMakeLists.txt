
cmake_minimum_required(VERSION 3.28)
project(robot_tour)

add_subdirectory(modules/pybind11)

pybind11_add_module(path_search simple_bfs.cpp)