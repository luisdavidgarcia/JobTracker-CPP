cmake_minimum_required(VERSION 3.31)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(JobTracker VERSION 1.0)

find_package(Boost REQUIRED COMPONENTS json)
find_package(PostgreSQL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(LIBPQXX REQUIRED libpqxx)

file(GLOB_RECURSE PROJECT_SOURCES ${CMAKE_SOURCE_DIR}/src/cpp/*.cpp)

add_executable(JobTracker ${PROJECT_SOURCES})

target_include_directories(JobTracker PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(JobTracker PRIVATE ${Boost_INCLUDE_DIRS})
target_include_directories(JobTracker PRIVATE ${LIBPQXX_INCLUDE_DIRS})

target_link_libraries(JobTracker PRIVATE
  ${LIBPQXX_LIBRARIES} 
  ${PostgreSQL_LIBRARIES}
  Boost::json
)

set(COMMON_FLAGS "-Wall -Werror")
set(DEBUG_FLAGS "-g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS}")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_FLAGS}")
endif()

option(ENABLE_TESTING "Enable unit tests" OFF)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(tests/cpp)
endif()
