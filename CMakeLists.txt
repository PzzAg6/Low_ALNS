cmake_minimum_required(VERSION 3.17)
project(ALNS)

set(CMAKE_CXX_STANDARD 14)

add_executable(ALNS main.cpp Node.cpp Node.h INPUT_DATA.cpp INPUT_DATA.h Route.cpp Route.h Solution.cpp Solution.h Gen_Init_Sol.cpp Gen_Init_Sol.h)