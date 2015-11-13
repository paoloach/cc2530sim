cmake_minimum_required(VERSION 3.3)
project(CC2530)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(loaderTest HexLineTest.cpp ../../loader/HexLine.cpp IntelHexDataTest.cpp ../../loader/IntelHexData.cpp ../../loader/IntelHexLine.cpp)

target_link_libraries(loaderTest gtest gtest_main)