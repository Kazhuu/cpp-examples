cmake_minimum_required(VERSION 3.0)
# Export compilation database for other tools to use. Vim YouCompleteMe uses
# this with symlink at project root.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cpp-examples)
add_executable(cpp-examples template_function/template_function.cpp template_function/main.cpp)

