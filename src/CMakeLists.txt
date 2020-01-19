# Add example directories each with own CMakeLists.txt files. CMake file in
# that subdirectory will get executed which will in turn build the executable
# out of that example.
add_subdirectory(template_function)
add_subdirectory(type_deduction)
add_subdirectory(ellipsis)
add_subdirectory(smart_pointers)
add_subdirectory(expression_types)
add_subdirectory(string)
add_subdirectory(move_semantics)
add_subdirectory(rule_of_three)
add_subdirectory(rule_of_five)
