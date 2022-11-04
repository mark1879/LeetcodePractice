cmake_minimum_required(VERSION 3.1)

project(LeetcodePractice)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/common/)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# MESSAGE(">>>>> GTEST dir: ")
# MESSAGE(${GTEST_INCLUDE_DIRS})
# MESSAGE(${GTEST_BOTH_LIBRARIES})
# MESSAGE(${GTEST_LIBRARIES})
# MESSAGE(${GTEST_MAIN_LIBRARIES})

add_subdirectory(HashTable/)
add_subdirectory(GreedyAlgorithm/)
add_subdirectory(Strings/)
add_subdirectory(TwoPointers/)
add_subdirectory(LinkedList/)
