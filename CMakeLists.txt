cmake_minimum_required(VERSION 3.10)

project(AztecDiamond CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(aztec-bin src/main.cpp src/AztecTilingCounter.cpp)

add_library(aztec-lib src/AztecTilingCounter.cpp)
target_include_directories(aztec-lib PUBLIC ${CMAKE_SOURCE_DIR}/src)

install(TARGETS aztec-bin DESTINATION bin)

add_subdirectory(test)
