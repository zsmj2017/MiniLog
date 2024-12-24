cmake_minimum_required(VERSION 3.31)

project(MiniLog)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(minilog_header_only INTERFACE)
add_library(MiniLog::minilog_header_only ALIAS minilog_header_only)

target_include_directories(minilog_header_only INTERFACE ${CMAKE_SOURCE_DIR}/include)

if (ENABLE_UT)
    add_subdirectory(tests/base-test)
endif()