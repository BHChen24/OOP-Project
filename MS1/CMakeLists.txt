cmake_minimum_required(VERSION 3.27)
project(MS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS1
        Date.cpp
        Date.h
        Menu.cpp
        Menu.h
        Utils.cpp
        Utils.h
        dateTester.cpp
        #menuTester.cpp
        #ms1_tester.cpp
)
