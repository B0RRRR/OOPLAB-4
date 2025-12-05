cmake_minimum_required(VERSION 3.16)
project(RotationFigures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Пути к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Основной исполняемый файл
set(SRC_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_executable(RotationFigures ${SRC_FILES})

# Файлы для тестов (включая все .cpp кроме main.cpp)
file(GLOB TEST_SRC ${CMAKE_SOURCE_DIR}/tests/*.cpp)

# Тестовый исполняемый файл
add_executable(UnitTests ${TEST_SRC})

# GTest
find_package(GTest REQUIRED)
if(GTest_FOUND)
    target_include_directories(UnitTests PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(UnitTests PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)
endif()

# Enable testing
enable_testing()
include(GoogleTest)
gtest_discover_tests(UnitTests)
