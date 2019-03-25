cmake_minimum_required(VERSION 3.9)
project(tp1_mochila)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SOURCE_FILES main.cpp prueba_integracion_con_gtest/test/factorialTest.cpp prueba_integracion_con_gtest/src/factorial.cpp tp1/test/knapbackTest.cpp tp1/scr/brute_force/Knapback.cpp tp1/scr/brute_force/Knapback.h tp1/scr/brute_force/Request.h)
add_executable(tp1_mochila ${SOURCE_FILES})

target_link_libraries(tp1_mochila gtest gtest_main)