cmake_minimum_required(VERSION 3.3)
project(cc2530sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(googletest/googlemock)
add_subdirectory(test/loader)


set(SOURCE_FILES main.cpp loader/HexLine.cpp loader/IntelHexData.cpp loader/IntelHexLine.cpp loader/IntelHexLoader.cpp Exceptions/InvalidIntelHexFile.cpp FlashMemory.cpp)
add_executable(cc2530sim ${SOURCE_FILES})