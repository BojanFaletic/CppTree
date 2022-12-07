cmake_minimum_required(VERSION 3.0.0)
project(parser VERSION 0.1.0)

#include(CTest)
#enable_testing()
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE src_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(inc)
add_executable(parser main.cpp ${src_files})


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message("running in debug mode")
  # Add the necessary flags for the debug configuration
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  # Add the necessary flags for the release configuration
  message("running in release mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
else()
  message("Unnown configuration")
endif()