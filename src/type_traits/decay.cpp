#include <iostream>
#include <type_traits>
#include <boost/type_index.hpp>

// std::decay converts types with three cases:
// * When array and function types are given they will be converted to pointer types.
// * When references are given, references will be removed and const and
//   volatile qualifiers as well.

template<class T>
void f(T&& param) {
    using boost::typeindex::type_id_with_cvr;

    // Use this with C++14.
    std::decay_t<T> decay_type = param;
    // Equivalent to above but need to be used with C++11.
    // typename std::decay<T>::type decay_type = param;
    std::cout << "before decay: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
    std::cout << "after decay: " << type_id_with_cvr<decltype(decay_type)>().pretty_name() << "\n" << std::endl;
}

int f2(int i) {
    return i;
}

// Each section shows how given type is converted by std::decay. Type in comment
// will be the type given by std::decay. For example int& will be decayed to
// int.
int main() {
    int x = 10;
    std::cout << "int&" << std::endl;
    f(x); // int
    std::cout << "int&&" << std::endl;
    f(10); // int
    const int y = 10;
    std::cout << "const int&" << std::endl;
    f(y); // int
    volatile const int z = 10;
    std::cout << "volatile const int&" << std::endl;
    f(z); // int
    int two_ints[2] = {1, 2};
    std::cout << "int[2]" << std::endl;
    f(two_ints); // int*
    std::cout << "string" << std::endl;
    f("aa"); // const char*
    std::cout << "function: int f2(int i);" << std::endl;
    f(f2); // int (*)(int)
}
