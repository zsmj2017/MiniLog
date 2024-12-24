cmake_minimum_required(VERSION 3.31)

project(MiniLog)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

message(STATUS "Include directory: ${CMAKE_SOURCE_DIR}/include")

add_executable(base-test tests/base-test/main.cpp)

target_include_directories(base-test PRIVATE ${CMAKE_SOURCE_DIR}/include)
