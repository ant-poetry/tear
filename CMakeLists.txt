cmake_minimum_required(VERSION 3.17)
project(tear C)

set(CMAKE_C_STANDARD 11)

add_executable(tear main.c collection/linked_list.h collection/linked_list.c collection/stack.h collection/stack.c)