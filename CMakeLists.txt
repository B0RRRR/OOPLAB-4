cmake_minimum_required(VERSION 3.16)
project(RotationFigures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(RotationFigures ${SRC_FILES})


set(TEST_SOURCES ${SRC_FILES})
list(REMOVE_ITEM TEST_SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)

file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)

add_executable(UnitTests ${TEST_SOURCES} ${TEST_FILES})

find_package(GTest REQUIRED)
if(GTest_FOUND)
    target_include_directories(UnitTests PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(UnitTests PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)
endif()

enable_testing()
include(GoogleTest)
gtest_discover_tests(UnitTests)
