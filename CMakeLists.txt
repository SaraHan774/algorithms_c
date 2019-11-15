cmake_minimum_required(VERSION 3.15)
project(algorithms_c C)

set(CMAKE_C_STANDARD 99)

add_executable(algorithms_c main.c bin_search.h search_sen.h)
add_executable(stack m_stack.c stack.h)
add_executable(bin_searh_comp bin_search_comp.h m_bin_search_comp.c)
add_executable(qsort qsort.c)