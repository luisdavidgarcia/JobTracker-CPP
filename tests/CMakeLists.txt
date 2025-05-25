find_package(Boost REQUIRED COMPONENTS unit_test_framework)

file(GLOB TEST_SOURCES "test_*.cpp")

file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

add_executable(JobTrackerTests ${TEST_SOURCES} ${PROJECT_SOURCES})

target_include_directories(JobTrackerTests PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${Boost_INCLUDE_DIRS}
)

target_link_libraries(JobTrackerTests PRIVATE 
  Boost::unit_test_framework
)

add_test(NAME JobTrackerTests COMMAND JobTrackerTests)
