set(SOURCE_FILES template_function.cpp)

add_executable(main main.cpp ${SOURCE_FILES})
add_executable(run_test test_template_function.cpp ${SOURCE_FILES})
target_link_libraries(run_test gtest_main)
