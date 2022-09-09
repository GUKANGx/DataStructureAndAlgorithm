cmake_minimum_required(VERSION 3.20)
project(DataStructureAndAlgorithmUsingCpp)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest-release-1.11.0/)

aux_source_directory(. SRC_LIST)
aux_source_directory(./LeetCode SRC_LIST)
include_directories(. )
include_directories(googletest-release-1.11.0/googletest/include googletest-release-1.11.0/googlemock/include)

add_executable(DataStructureAndAlgorithmUsingCpp ${SRC_LIST})
target_link_libraries(DataStructureAndAlgorithmUsingCpp gtest gtest_main)
target_link_libraries(DataStructureAndAlgorithmUsingCpp gmock gmock_main)
