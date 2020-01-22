cmake_minimum_required(VERSION 3.15)
project(snake)

set(CMAKE_CXX_STANDARD 11)

add_executable(snake main.cpp textConst.h sysFunc.h sysFunc.cpp gameEngine.cpp gameEngine.h display.h display.cpp readWriteFile.cpp readWriteFile.h scores.cpp scores.h)