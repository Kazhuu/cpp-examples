#include "namespace_header.h"
#include <iostream>

// Executing this will print:
// print_i is 5
// i is 20
// print_i is 10
int main()
{
    test::print_i();
    // This variable refers to (this) static_in_namespace translation unit's
    // test::i variable which is different from static_in_namespace translation
    // unit with test namespace which has it's own test::i variable.
    test::i = 20;
    test::set_i();
    std::cout << "i is " << test::i << std::endl;
    test::print_i();
    return 0;
}
