cmake_minimum_required(VERSION 3.3)
project(CC2530)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp FlashMemory.cpp FlashMemory.h loader/IntelHexLoader.cpp loader/IntelHexLoader.h loader/IntelHexLine.cpp loader/IntelHexLine.h loader/IntelHexData.cpp loader/IntelHexData.h Exceptions/InvalidIntelHexFile.cpp Exceptions/InvalidIntelHexFile.h)
add_executable(CC2530 ${SOURCE_FILES})