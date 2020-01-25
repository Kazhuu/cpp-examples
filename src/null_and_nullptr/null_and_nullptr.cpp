#include <boost/type_index.hpp>
#include <iostream>

/*
 * Prefer using nullptr over 0 and NULL. Example taken from the book Effective
 * Modern C++ by Scott Meyers from item 8.
 */

void f(int)
{
    std::cout << "int overload called" << std::endl;
}

void f(void*)
{
    std::cout << "void* overload called" << std::endl;
}

int main()
{
    f(0); // Will call f(int).
    //f(NULL); // Will not compile, but if did it would not call f(void*).
    f(nullptr); // Will call f(void*) correctly.

    /*
     * Problem with NULL is that its type can be integral type int or long. It
     * is not a pointer type like nullptr. So to demonstrate this auto can be
     * used. With NULL assignment on GCC variable's type will be deduced to be
     * a long type. GCC will emit warning about this. On the other hand
     * assigning nullptr variable's type will be deduced to be a pointer, which
     * is what we want.
     */
    using boost::typeindex::type_id_with_cvr;
    auto x = NULL;
    auto px = nullptr;
    std::cout << "auto x = NULL -> " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
    // auto x = NULL -> long
    std::cout << "auto px = nullptr -> " << type_id_with_cvr<decltype(px)>().pretty_name() << std::endl;
    // auto px = nullptr -> decltype(nullptr)
}
