enable_testing()

find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(aztec_test AztecTilingCounterTest.cpp)

target_link_libraries(aztec_test GTest::gtest_main aztec-lib)

include(GoogleTest)
gtest_discover_tests(aztec_test)