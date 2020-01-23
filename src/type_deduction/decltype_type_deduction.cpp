#include <vector>
#include <iostream>
#include <boost/type_index.hpp>

/*
 * How decltype() type deduction works. Examples taken from the book Effective
 * Modern C++ by Scott Meyers from item 3. Type printing is taken from the same
 * book but from item 4.
 *
 * Decltype doesn't work with the same rules as auto and template type
 * deduction. Using decltype will not strip off references from variables like
 * auto and template type deduction does. Primary use case of decltype in C++11
 * is declaring function templates where function return type depends on its
 * parameter type.
 */

bool f()
{
    return true;
}

/*
 * This function uses auto type deduction rules for function return value, which
 * will cause param's reference to be stripped off and type T will be returned
 * instead, not T&.
 */
template<typename T>
auto auto_return_type_deduction(T& param)
{
    return param;
}

/*
 * This function will use auto meaning that deduce type from return statement
 * but use decltype rules for it. Which will not strip off reference from type.
 * This behaviour can be achieved by writing decltype(auto). This function will
 * return T& correctly.
 */
template<typename T>
decltype(auto) decltype_return_type_deduction(T& param)
{
    return param;
}

int main()
{
    using boost::typeindex::type_id_with_cvr;

    std::cout << "decltype() with variables:" << std::endl;
    const int x = 1;
    std::cout << "const int x -> " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
    // const int x -> int const

    // Notice decltype doesn't strip off reference.
    const int& rx = x;
    std::cout << "const int& rx -> " << type_id_with_cvr<decltype(rx)>().pretty_name() << std::endl;
    // const int& rx -> int const&

    // Notice decltype doesn't strip off reference.
    int&& rrx = 10;
    std::cout << "int& rrx -> " << type_id_with_cvr<decltype(rrx)>().pretty_name() << std::endl;
    // int& rrx -> int&&

    const int* px = &x;
    std::cout << "const int* px -> " << type_id_with_cvr<decltype(px)>().pretty_name() << std::endl;
    // const int* px -> int const*

    std::vector<int> int_vector;
    std::cout << "std::vector<int> -> " << type_id_with_cvr<decltype(int_vector)>().pretty_name() << std::endl;
    // std::vector<int> -> std::vector<int, std::allocator<int> >

    std::cout << "f() -> " << type_id_with_cvr<decltype(f())>().pretty_name() << std::endl;
    // f() -> bool


    std::cout << "\nauto and decltype(auto) with function return type deduction:" << std::endl;
    // Notice auto type deduction strips returned variable reference. This will
    // happen with both lvalue and rvalue references.
    int y = 10;
    std::cout << "auto auto_return_type_deduction(int&) -> " << type_id_with_cvr<decltype(auto_return_type_deduction<int>(y))>().pretty_name() << std::endl;
    // auto_return_type_deduction() -> int

    /*
     * Using decltype(auto) will return variable correctly with reference. Here
     * auto means "deduce function return type from return statement" and
     * decltype means "use decltype type deduction rules", hence decltype(auto).
     * This works for both lvalue and rvalue references.
     */
    std::cout << "decltype(auto) decltype_return_type_deduction(int&) -> " << type_id_with_cvr<decltype(decltype_return_type_deduction<int>(y))>().pretty_name() << std::endl;
    // decltype_return_type_deduction() -> int&


    // decltype(auto) type deduction rules can also be used with variables.
    std::cout << "\ndecltype(auto) with variables:" << std::endl;
    int a = 10;
    const int& ra = a;
    // Notice that reference and const will be removed with auto which is not the
    // case with decltype(auto)
    auto aa = ra; // Type will be int.
    std::cout << "auto aa = const int& -> " << type_id_with_cvr<decltype(aa)>().pretty_name() << std::endl;
    decltype(auto) da = ra; // Type will be const int&.
    std::cout << "decltype(auto) da = const int& -> " << type_id_with_cvr<decltype(da)>().pretty_name() << std::endl;


    /*
     * When giving expression other than name to decltype, it will return
     * reference instead. For instance decltyp((x)) will report int& instead of
     * int. Small difference you should be aware of when using decltype and
     * decltype(auto).
     */
    std::cout << "\ndecltype(auto) weird behaviour with expression type other than names" << std::endl;
    std::cout << "decltype(x) -> " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
    std::cout << "decltype((x)) -> " << type_id_with_cvr<decltype((x))>().pretty_name() << std::endl;
}
