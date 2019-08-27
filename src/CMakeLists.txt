cmake_minimum_required(VERSION 3.0)
# Export compilation database for other tools to use. Vim YouCompleteMe uses
# this with symlink at project root.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cpp-examples)

# Enable testing and add google test.
enable_testing()
add_subdirectory(ext/googletest)

# Add example directories each with own CMakeLists.txt files.
add_subdirectory(template_function)
