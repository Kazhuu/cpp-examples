cmake_minimum_required(VERSION 3.0)
# Use latest C++15 standard.
set(CMAKE_CXX_STANDARD 20)

project(cpp-examples)

# Export compilation database for other tools to use. Vim YouCompleteMe uses
# this with symlink at project root.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable testing and add google test.
enable_testing()
add_subdirectory(ext/googletest)

# Add example directories each with own CMakeLists.txt files.
add_subdirectory(template_function)
add_subdirectory(ellipsis)
add_subdirectory(smart_pointers)
add_subdirectory(expression_types)