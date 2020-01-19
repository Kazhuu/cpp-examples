cmake_minimum_required(VERSION 3.8)

# Required C++17 support at least and disable compiler extensions like GNU.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cpp-examples)

# Export compilation database for other tools to use. Vim YouCompleteMe uses
# this with symlink at project root.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable testing and add google test.
enable_testing()
add_subdirectory(ext/googletest)
# Add code examples. This will execute subfolder CMake file in
# src/CMakeLists.txt.
add_subdirectory(src)
