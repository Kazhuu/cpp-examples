#include "namespace_header.h"
#include "iostream"

// Here i variable refers to (this) namespace_header translation unit's test::i variable.
void test::set_i()
{
    i = 10;
}

void test::print_i()
{
    std::cout << "print_i is " << i << std::endl;
}
