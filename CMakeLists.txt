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


# add_subdirectory(hash_table/)
# add_subdirectory(greedy_algorithm/)
# add_subdirectory(strings/)
# add_subdirectory(two_pointers/)
# add_subdirectory(linked_list/)
# add_subdirectory(binary_search_tree/)
add_subdirectory(dynamic_programming/)
# add_subdirectory(prefix_sum/)
