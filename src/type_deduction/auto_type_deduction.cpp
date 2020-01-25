#include <iostream>
#include <boost/type_index.hpp>

/*
 * How auto type deduction works. Examples taken from the book Effective
 * Modern C++ by Scott Meyers from item 2. Type printing is taken from the same
 * book but from item 4.
 *
 * Like template type deduction example type specifier for variable has
 * following three cases to cover:
 * * Type specifier is a pointer or reference type, but not a universal reference,
 * * Type specifier is a universal reference,
 * * Type specifier is neither a pointer nor a reference.
 */
int main()
{
    using boost::typeindex::type_id_with_cvr;

    int x = 30;
    const int cx = x;
    const int& rx = x;
    const int *px = &x;

    // Case 1: Type specifier is a pointer or reference, but not a universal
    // reference.
    std::cout << "Case 1: ParamType is a reference or pointer, but not a universal reference" << std::endl;
    const auto& x1 = x;
    std::cout << "const auto& = int -> " << type_id_with_cvr<decltype(x1)>().pretty_name() << std::endl;
    // const auto& = int -> int const&

    // Case 2: Type specifier is a universal reference. With universal reference
    // reference collapsing takes place for type deduction. Check item 28 from
    // the book for more information.
    std::cout << std::endl << "Case 2: ParamType is a universal/forwarding reference" << std::endl;
    auto&& ux1 = x; // Assigning lvalue causes ux1 type to be lvalue reference.
    std::cout << "auto&& = int -> " << type_id_with_cvr<decltype(ux1)>().pretty_name() << std::endl;
    // auto&& = int -> int&
    auto&& ux2 = rx; // Same as above but constness is kept.
    std::cout << "auto&& = const int& -> " << type_id_with_cvr<decltype(ux2)>().pretty_name() << std::endl;
    // auto&& = const int& -> int const&
    auto&& ux3 = 10; // Assigning rvalue causes ux3 type to be rvalue too.
    std::cout << "auto&& = 10 -> " << type_id_with_cvr<decltype(ux3)>().pretty_name() << std::endl;
    // auto&& = 10 -> int&&

    // Case 3: Type specifier is neither a pointer nor a reference.
    std::cout << std::endl << "Case 3: ParamType is neither a pointer nor a reference" << std::endl;
    auto x3 = x;
    std::cout << "auto = x -> " << type_id_with_cvr<decltype(x3)>().pretty_name() << std::endl;
    // auto = x -> int
    const auto cx3 = x;
    std::cout << "const auto = x -> " << type_id_with_cvr<decltype(cx3)>().pretty_name() << std::endl;
    // const auto = x -> int const

    // Small detail when auto type deduction differs from template type
    // deduction when using C++11 uniform initialization with curly brackets.
    // When = is preceding first curly bracket, then deduced type will be
    // std::initializer_list<T>, not type T. This doesn't happen with template
    // type deduction. In some cases x4{30} will also be deduced as
    // std::initializer_list<T>. Check this stackoverflow for more information:
    // https://stackoverflow.com/questions/25612262/why-does-auto-x3-deduce-an-initializer-list
    std::cout << std::endl << "Special case with std::initializer_list<T>" << std::endl;
    auto x4{30};
    std::cout << "auto x4{30} -> " << type_id_with_cvr<decltype(x4)>().pretty_name() << std::endl;
    // auto x4{30} -> int
    auto x5 = {30};
    std::cout << "auto x5 = {30} -> " << type_id_with_cvr<decltype(x5)>().pretty_name() << std::endl;
    // auto x5 = {30} -> std::initializer_list<int>
}
