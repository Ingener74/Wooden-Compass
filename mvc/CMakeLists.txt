cmake_minimum_required(VERSION 3.0)

set(SOURCES
    src/DataSource.cpp
    src/DataSink.cpp
)

add_library(mvc ${SOURCES})

add_executable(mvctests tests/tests.cpp)
target_link_libraries(mvctests mvc gtest gtest_main gmock)
add_test(AllTests mvctests)
