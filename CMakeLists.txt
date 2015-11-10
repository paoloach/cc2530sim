cmake_minimum_required(VERSION 3.3)
project(CC2530)

configure_file(gtest-CMakeLists.txt gtest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )

# Add gtest directly to our build
add_subdirectory(${CMAKE_BINARY_DIR}/gtest-src  ${CMAKE_BINARY_DIR}/gtest-build EXCLUDE_FROM_ALL )

# Add the gtest include directory, since gtest
# doesn't add that dependency to its gtest target
target_include_directories(gtest INTERFACE
        "${CMAKE_BINARY_DIR}/gtest-src/include" )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp FlashMemory.cpp FlashMemory.h loader/IntelHexLoader.cpp loader/IntelHexLoader.h loader/IntelHexLine.cpp loader/IntelHexLine.h loader/IntelHexData.cpp  Exceptions/InvalidIntelHexFile.cpp Exceptions/InvalidIntelHexFile.h loader/HexLine.cpp loader/HexLine.h tests/loader/HexLineTest.cpp)
add_executable(CC2530 ${SOURCE_FILES})