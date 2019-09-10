#include <string>
#include <iostream>


// An rvalue reference in C++ is a way to reference short lived temporary value
// and is denoted with &&. "int&& name" for example. It lets you modify
// temporary value without constant lvalue reference.
int main()
{
    std::string hello = "Hello";
    std::string world = "World";
    // Cannot bind resulted rvalue string to non-constant lvalue reference.
    // std::string& hello_world = hello + world;
    // Constant lvalue can be binded to to an rvalue.
    const std::string& const_hello_world = hello + world;
    // Resulted string can be binded to rvalue reference and modified later. No
    // need for constant here.
    std::string&& hello_world = hello + world;
    hello_world += "ddddd!";
    std::cout << hello_world << std::endl;
}
