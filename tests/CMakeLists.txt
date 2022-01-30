project(tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run MatchingEngine.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main src)
target_link_libraries(Google_Tests_run gmock gmock_main src)
