# TODO: When executing executable it doens't find any tests. Running ctest does.
add_executable(test_template_function template_function.cpp test_template_function.hpp)
target_link_libraries(test_template_function gtest_main)
add_test(NAME test_template_function COMMAND test_template_function)