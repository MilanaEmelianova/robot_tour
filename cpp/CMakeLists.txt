project(robot_tour)
cmake_minimum_required(VERSION 3.28)

add_subdirectory(modules/pybind11)

pybind11_add_module(path_search simple_bfs.cpp)