#include <iostream>

// Function returning rvalue, short lived integer.
int return_rvalue()
{
    return 10;
}

int global_int = 11;
// Function returning lvalue of the global integer with reference to int (int&).
int& return_lvalue()
{
    return global_int;
}

// This function definition takes non-constant lvalue reference as an argument.
void take_non_const_reference(int& value)
{
    std::cout << "non-constant lvalue reference: " << value << std::endl;
}

// This function definition takes constant lvalue reference as an argument.
void take_const_reference(const int& value)
{
    std::cout << "constant lvalue reference: " << value << std::endl;
}

/*
 * An lvalue is a type of expression that points to something and an rvalue is type of expression that
 * doesn't point anywhere. lvalue for long lived values and rvalue for short lived values.
 *
 * This tutorial was followed: https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c
 */
int main()
{
    // 12 is an rvalue and x is an lvalue.
    int x = 12;
    // Address-of operator & takes an lvalue and converts it to rvalue.
    int* y = &x;
    // Prints "error: lvalue required as left operand of assignment". This is because lvalue is required
    // for the assignment.
    // 13 = x;
    // Prints "error: lvalue required as unary '&' operand".
    // int* y = &13;

    // Illegal assignment with message "error: lvalue required as left operand of assignment".
    // return_rvalue() = 10;
    // Valid assignment because function returning lvalue.
    return_lvalue() = 10;

    // lvalue reference.
    int a = 10;
    int& a_ref = a;
    a_ref++; // a == 11
    std::cout << "a: " << a << std::endl;

    // When function is taking a non-constant lvalue reference as a parameter then rvalue
    // (value 10) cannot be given because it's illegal rvalue to lvalue
    // conversion. Commented line below fails with error: cannot bind non-const lvalue reference of
    // type ‘int&’ to an rvalue of type ‘int’.
    // take_non_const_reference(10);

    // Instead storing 10 to lvalue first and then giving it as parameter works
    // fine.
    int value = 10;
    take_non_const_reference(value);
    // However if function takes constant lvalue reference then it's possible
    // to give rvalue as parameter without first saving it to lvalue.
    take_const_reference(10);
}


