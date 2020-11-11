cmake_minimum_required(VERSION 3.17)
project(tear C)

set(CMAKE_C_STANDARD 11)

add_executable(tear main.c collection/linked_list.h collection/linked_list.c collection/stack.h collection/stack.c collection/queue.h collection/queue.c util/util.h util/types.h unicode/unicode.h unicode/utf8/utf8.h collection/binary_tree.h collection/binary_tree.c collection/binary_search_tree.h collection/binary_search_tree.c)