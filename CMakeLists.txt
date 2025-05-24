cmake_minimum_required(VERSION 3.31)
project(JobTracker VERSION 1.0)

find_package(Boost REQUIRED)

add_executable(JobTracker src/main.cpp)
target_include_directories(JobTracker PRIVATE ${Boost_INCLUDE_DIRS})

option(ENABLE_TESTING "Enable unit tests" OFF)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
