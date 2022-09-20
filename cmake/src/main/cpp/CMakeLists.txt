cmake_minimum_required(VERSION 3.18.1)

project("test")

file(GLOB SOURCE *.cpp *.c)

add_library(test SHARED ${SOURCE})

find_library(log-lib log)

target_link_libraries(test ${log-lib})