cmake_minimum_required(VERSION 2.8)
project(cc2530sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g2")

add_subdirectory(googletest/googlemock)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(instruction_lib OBJECT
        instruction/Instruction.cpp
        instruction/InstructionFactory.cpp
        instruction/UnknownInstruction.cpp
        instruction/RegistryUtil.cpp instruction/RegistryUtil.h registers/DPL0.cpp registers/DPL0.h registers/DPH0.cpp registers/DPH0.h registers/Acc.cpp registers/Acc.h registers/FMAP.cpp registers/FMAP.h instruction/InstructionAdd.cpp instruction/InstructionAdd.h)


add_library(loader_lib OBJECT
        loader/HexLine.cpp loader/IntelHexLine.cpp loader/IntelHexData.cpp loader/IntelHexLoader.cpp
        loader/IntelEndOfFile.cpp loader/IntelEndOfFile.h loader/IntelHexExtendedLinearAddress.cpp
        loader/IntelHexExtendedLinearAddress.h loader/IntelHexInvalidLine.cpp loader/IntelHexInvalidLine.h
        loader/IntelHexStartLinearAddress.cpp loader/IntelHexStartLinearAddress.h)

set(SOURCE_FILES main.cpp Exceptions/InvalidIntelHexFile.cpp FlashMemory.cpp MemoryLocation.cpp MemoryLocation.h
        CPU.cpp CPU.h Registers.h XData.cpp XData.h)


add_executable(cc2530sim ${SOURCE_FILES} $<TARGET_OBJECTS:instruction_lib> $<TARGET_OBJECTS:loader_lib>)
add_executable(loaderTest test/loader/HexLineTest.cpp test/loader/IntelHexDataTest.cpp test/loader/IntelHexFinishedTest.cpp test/loader/IntelHexExtendedLinearAddressTest.cpp $<TARGET_OBJECTS:loader_lib>)

target_link_libraries(loaderTest gtest gtest_main)

