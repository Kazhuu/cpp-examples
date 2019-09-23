cmake_minimum_required(VERSION 3.0)

project(cpp-examples)

# Export compilation database for other tools to use. Vim YouCompleteMe uses
# this with symlink at project root.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable testing and add google test.
enable_testing()
add_subdirectory(ext/googletest)
# Add code examples. This will execute subfolder CMakeLists.txt files.
add_subdirectory(src)
