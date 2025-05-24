find_package(Boost REQUIRED  COMPONENTS  unit_test_framework)

file(GLOB TEST_SOURCES *.cpp)

file(GLOB_RECURSE PROJECT_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

list(FILTER PROJECT_SOURCES EXCLUDE  REGEX ".*/main\\.cpp$")

add_executable(unit_tests 
  ${TEST_SOURCES}
  ${PROJECT_SOURCES}
)

target_include_directories(unit_tests PRIVATE 
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(unit_tests PRIVATE Boost::unit_test_framework)

add_test(NAME AllTests COMMAND unit_tests)
