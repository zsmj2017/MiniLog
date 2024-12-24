cmake_minimum_required(VERSION 3.31)

project(MiniLogBaseTest)

if (NOT TARGET minilog_header_only)
    find_package(minilog_header_only REQUIRED)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(base-test main.cpp)
target_link_libraries(base-test PRIVATE MiniLog::minilog_header_only)