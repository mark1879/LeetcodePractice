
# message(">>> PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
# message(">>> CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(test_two_sum test_two_sum.cpp)

target_link_libraries(test_two_sum ${GTEST_BOTH_LIBRARIES})

