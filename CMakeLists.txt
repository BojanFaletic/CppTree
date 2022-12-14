cmake_minimum_required(VERSION 3.0.0)
project(parser VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE src_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(inc)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

add_executable(parser main.cpp ${src_files})
add_executable(test tests.cpp ${src_files})
add_executable(bench benchmark.cpp ${src_files})

target_link_libraries(test PRIVATE GTest::GTest GTest::Main)
target_link_libraries(bench PRIVATE benchmark::benchmark)



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
