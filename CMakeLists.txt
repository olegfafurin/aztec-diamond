cmake_minimum_required(VERSION 3.10)

project(AztecDiamond CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(aztec src/main.cpp src/AztecTilingCounter.cpp)

install(TARGETS aztec DESTINATION bin)
