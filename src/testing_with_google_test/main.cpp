#include <iostream>
#include "function.hpp"

/*
 * Application's main executable which is not related to written tests.
 *
 * How main executable and test executable share common project files check
 * CMakeLists.txt in this folder for more information.
 */
int main()
{
    std::cout << "test_function: " << test_function(true) << std::endl;
}
