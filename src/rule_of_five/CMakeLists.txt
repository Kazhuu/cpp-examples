set(SOURCE_FILES
	holder.cpp
	rule_of_five.cpp
)

add_executable(rule_of_five ${SOURCE_FILES})
# Disable Return Value Optimization (RVO) so that move constructor in this
# example will be called.
target_compile_options(rule_of_five PRIVATE -fno-elide-constructors)
