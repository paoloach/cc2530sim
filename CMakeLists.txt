cmake_minimum_required(VERSION 2.8)
project(cc2530sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g2")

add_subdirectory(googletest/googlemock)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(INSTRUCTION_FILE  instruction/Instruction.cpp instruction/Instruction.h instruction/LongJump.cpp instruction/LongJump.h instruction/Nop.cpp instruction/Nop.h instruction/InstructionFactory.cpp instruction/InstructionFactory.h)

set(SOURCE_FILES main.cpp Exceptions/InvalidIntelHexFile.cpp FlashMemory.cpp MemoryLocation.cpp MemoryLocation.h CPU.cpp CPU.h )

SET(SOURCE_LOADER_SRC loader/HexLine.cpp loader/IntelHexLine.cpp loader/IntelHexData.cpp loader/IntelHexLoader.cpp loader/IntelEndOfFile.cpp loader/IntelEndOfFile.h loader/IntelHexExtendedLinearAddress.cpp loader/IntelHexExtendedLinearAddress.h loader/IntelHexInvalidLine.cpp loader/IntelHexInvalidLine.h loader/IntelHexStartLinearAddress.cpp loader/IntelHexStartLinearAddress.h )

add_library(loader_lib  OBJECT  ${INSTRUCTION_FILE})
add_library(instruction_lib  OBJECT  ${SOURCE_LOADER_SRC})
add_executable(cc2530sim ${SOURCE_FILES} $<TARGET_OBJECTS:loader_lib> $<TARGET_OBJECTS:instruction_lib>)
add_executable(loaderTest test/loader/HexLineTest.cpp  test/loader/IntelHexDataTest.cpp test/loader/IntelHexFinishedTest.cpp test/loader/IntelHexExtendedLinearAddressTest.cpp $<TARGET_OBJECTS:loader_lib>)

target_link_libraries(loaderTest gtest gtest_main)

