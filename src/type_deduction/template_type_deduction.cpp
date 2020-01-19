#include <boost/type_index.hpp>

/*
 * How template type deduction works. Examples taken from the book Effective
 * Modern C++ by Scott Meyers from item 1.
 *
 * template<typename T>
 * void f(ParamType param);
 *
 * Type deduction for T and ParamType has three cases:
 * * ParamType is a pointer or reference type, but not a universal reference,
 * * ParamType is a universal reference,
 * * ParamType is neither a pointer nor a reference.
 */

// Case 1: ParamType is a reference or pointer, but not a universal reference.

template<typename T>
void f(T& param)
{
    using boost::typeindex::type_id_with_cvr;
    std::cout << "T: " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "param: " << type_id_with_cvr<param>().pretty_name() << std::endl;
}

int x = 30;
int cx = x;
int rx = &x;

f(x); // T is int, param's type is int&.
f(cx); // T is int, param's type is int&.
