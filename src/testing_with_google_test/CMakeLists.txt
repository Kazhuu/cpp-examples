# Set variable SOURCE_FILES. This will include all application files which will
# be shared with main executable and test executable.
set(SOURCE_FILES function.cpp)

# Add application main executable with main() which will be linked with files
# in SOURCE_FILES and main.cpp.
add_executable(run_main main.cpp ${SOURCE_FILES})

# Add executable which is used to execute tests and link it with test.cpp and
# files in SOURCE_FILES.
add_executable(run_test test.cpp ${SOURCE_FILES})
# Now because executable to run tests is missing main() function, link it with
# gtest_main which contain simple main() to run tests. This is provided by
# google testing library.
target_link_libraries(run_test gtest_main)
