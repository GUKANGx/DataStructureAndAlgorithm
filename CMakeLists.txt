cmake_minimum_required(VERSION 3.20)
project(DataStructureAndAlgorithmUsingCpp)

set(CMAKE_CXX_STANDARD 11)

# add *.h dirs
include_directories(.)

# find all *.cpp files
aux_source_directory(. SRC_LIST)

add_executable(DataStructureAndAlgorithmUsingCpp ${SRC_LIST})
