cmake_minimum_required(VERSION 2.8)
project(cc2530sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g2")
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
find_package(Boost COMPONENTS log REQUIRED)

add_subdirectory(googletest/googlemock)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${Boost_INCLUDE_DIRS})

add_library(instruction_lib OBJECT
        instruction/Instruction.cpp
        instruction/InstructionFactory.cpp
        instruction/UnknownInstruction.cpp
        instruction/RegistryUtil.cpp
        instruction/RegistryUtil.h
        registers/DPL0.cpp
        registers/DPL0.h
        registers/DPH0.cpp
        registers/DPH0.h
        registers/Acc.cpp
        registers/Acc.h
        registers/FMAP.cpp
        registers/FMAP.h
        instruction/InstructionAdd.cpp instruction/InstructionAdd.h
        instruction/InstructionXCH.cpp
        instruction/InstructionSub.cpp
        instruction/InstructionBranch.cpp
        registers/T1STAT.cpp
        registers/T1STAT.h
        instruction/InstructionMov.cpp
        instruction/InstructionInc.cpp
        instruction/InstructionORL.cpp
        instruction/InstructionDec.cpp registers/DPL1.h registers/IP0.h)


add_library(loader_lib OBJECT
        loader/HexLine.cpp loader/IntelHexLine.cpp loader/IntelHexData.cpp loader/IntelHexLoader.cpp
        loader/IntelEndOfFile.cpp loader/IntelEndOfFile.h loader/IntelHexExtendedLinearAddress.cpp
        loader/IntelHexExtendedLinearAddress.h loader/IntelHexInvalidLine.cpp loader/IntelHexInvalidLine.h
        loader/IntelHexStartLinearAddress.cpp loader/IntelHexStartLinearAddress.h)

set(SOURCE_FILES main.cpp Exceptions/InvalidIntelHexFile.cpp FlashMemory.cpp MemoryLocation.cpp MemoryLocation.h
        CPU.cpp CPU.h Registers.h XData.cpp XData.h InstructionPointer.cpp InstructionPointer.h Data8.cpp Data8.h)


add_executable(cc2530sim ${SOURCE_FILES} $<TARGET_OBJECTS:instruction_lib> $<TARGET_OBJECTS:loader_lib>)
add_executable(loaderTest test/loader/HexLineTest.cpp test/loader/IntelHexDataTest.cpp test/loader/IntelHexFinishedTest.cpp test/loader/IntelHexExtendedLinearAddressTest.cpp $<TARGET_OBJECTS:loader_lib>)

target_link_libraries(cc2530sim ${Boost_LIBRARIES} pthread)
target_link_libraries(loaderTest gtest gtest_main ${Boost_LOG_LIBRARY_RELEASE})

