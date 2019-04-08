cmake_minimum_required(VERSION 3.9)
project(tp1_mochila)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SOURCE_FILES main.cpp prueba_integracion_con_gtest/test/factorialTest.cpp prueba_integracion_con_gtest/src/factorial.cpp tp1/test/KnapbackTest.cpp tp1/scr/KnapbackDesitionTree.cpp tp1/scr/KnapbackDesitionTree.h tp1/scr/Request.h tp1/scr/brute_force/BruteForce.cpp tp1/scr/brute_force/BruteForce.h tp1/scr/DesitionTreeStrategy.h tp1/scr/backtracking/Backtracking.cpp tp1/scr/backtracking/Backtracking.h tp1/test/BacktrackingTest.cpp tp1/scr/Knapback.h tp1/scr/meet_in_the_middle/MeetInTheMiddle.cpp tp1/scr/meet_in_the_middle/MeetInTheMiddle.h tp1/scr/meet_in_the_middle/Solution.h tp1/test/MeetInTheMiddleTest.cpp)
add_executable(tp1_mochila ${SOURCE_FILES})

target_link_libraries(tp1_mochila gtest gtest_main)