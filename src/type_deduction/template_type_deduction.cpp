#include <iostream>
#include <boost/type_index.hpp>

/*
 * How template type deduction works. Examples taken from the book Effective
 * Modern C++ by Scott Meyers from item 1. Type printing is taken from the same
 * book but from item 4.
 *
 * template<typename T>
 * void f(ParamType param);
 *
 * Type deduction for T and ParamType has three cases:
 * * ParamType is a pointer or reference type, but not a universal reference,
 * * ParamType is a universal reference,
 * * ParamType is neither a pointer nor a reference.
 */

template<typename T>
void f_reference(T& param)
{
    using boost::typeindex::type_id_with_cvr;
    std::cout << "T: " << type_id_with_cvr<T>().pretty_name() << ", param: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}

template<typename T>
void f_const_reference(const T& param)
{
    using boost::typeindex::type_id_with_cvr;
    std::cout << "T: " << type_id_with_cvr<T>().pretty_name() << ", param: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}

template<typename T>
void f_pointer(T* param)
{
    using boost::typeindex::type_id_with_cvr;
    std::cout << "T: " << type_id_with_cvr<T>().pretty_name() << ", param: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}

template<typename T>
void f_universal(T&& param)
{
    using boost::typeindex::type_id_with_cvr;
    std::cout << "T: " << type_id_with_cvr<T>().pretty_name() << ", param: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}

template<typename T>
void f_value(T param)
{
    using boost::typeindex::type_id_with_cvr;
    std::cout << "T: " << type_id_with_cvr<T>().pretty_name() << ", param: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}

int main()
{

    int x = 30;
    const int cx = x;
    const int& rx = x;
    const int *px = &x;

    /*
     * Case 1: ParamType is a reference or pointer, but not a universal reference.
     * Rules for type deduction for this case:
     * 1. If expr's type is a reference, ignore the reference part.
     * 2. Then pattern-match expr's type against ParamType to determine T.
     */
    std::cout << "Case 1: ParamType is a reference or pointer, but not a universal reference" << std::endl;

    std::cout << "ParamType = T&:" << std::endl;
    std::cout << "int -> ";
    f_reference(x); // T = int, param = int&
    std::cout << "const int -> ";
    f_reference(cx); // T = const int, param = const int&
    std::cout << "const int& -> ";
    f_reference(rx); // T = const int, param = const int&

    std::cout << "ParamType = const T&:" << std::endl;
    std::cout << "int -> ";
    f_const_reference(x); // T = int, param = const int&
    std::cout << "const int -> ";
    f_const_reference(cx); // T = int, param = const int&
    std::cout << "const int& -> ";
    f_const_reference(rx); // T = int, param = const int&

    std::cout << "ParamType = T*:" << std::endl;
    std::cout << "int* -> ";
    f_pointer(&x); // T = int, param = int*.
    std::cout << "const int* -> ";
    f_pointer(px); // T = const int, param = const int*

    /*
     * Universal reference can hold both rvalue and lvalue references. If expr
     * is lvalue both T and ParamType are deduced to be lvalue references.
     * Reference collapsing take place here and that's why T&& will end up
     * deduced to be T&. When expr is rvalue then case 1 rules apply.
     */
    std::cout << std::endl << "Case 2: ParamType is a universal/forwarding reference" << std::endl;

    std::cout << "ParamType = T&&:" << std::endl;
    std::cout << "lvalue int -> ";
    f_universal(x); // T = int&, param = int&
    std::cout << "lvalue const int -> ";
    f_universal(cx); // T = const int&, param = const int&
    std::cout << "lvalue const int& -> ";
    f_universal(rx); // T = const int&, param = const int&
    std::cout << "rvalue int -> ";
    f_universal(30); // T = int, param = int&&


    /* When ParamType is neither pointer nor a reference, we are dealing with
     * pass-by-value cases. Passed parameter will be copied when passed to the
     * template function.
     * Rules for this type deduction:
     * 1. If expr's type is reference, ignore the reference part.
     * 2. After reference also ignore const and volatile modifiers.
     */
    std::cout << std::endl << "Case 3: ParamType is neither a pointer nor a reference" << std::endl;

    std::cout << "ParamType = T:" << std::endl;
    std::cout << "int -> ";
    f_value(x); // T = int, param = int
    std::cout << "const int -> ";
    f_value(cx); // T = int, param = int
    std::cout << "const int& -> ";
    f_value(rx); // T = int, param = int
}
