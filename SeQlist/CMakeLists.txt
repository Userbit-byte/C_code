cmake_minimum_required(VERSION 3.23)
project(SeQlist C)

set(CMAKE_C_STANDARD 99)

add_executable(SeQlist test.c SeqList.c SeqList.h)
