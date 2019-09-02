#include <iostream>

// Function returning rvalue, short lived integer.
int return_rvalue() {
	return 10;
}

int global_int = 11;
// Function returning lvalue of the global interger with reference to int (int&).
int& return_lvalue() {
	return global_int;
}

/*
 * An lvalue is a type of expression that points to something and an rvalue is type of expression that
 * doesn't point anywhere. lvalue for long lived values and rvalue for short lived values.
 *
 * This tutorial was followed: https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c
 */
int main() {
	// 12 is an rvalue and x is an lvalue.
	int x = 12;
	// Address-of operator & takes an lvalue and convers it to rvalue.
	int* y = &x;
	// Prints "error: lvalue required as left operand of assignment". This is because lvalue is required
	// for the assignment.
	// 13 = x;
	// Prints "error: lvalue required as unary '&' operand".
	// int* y = &13;

	// Illegal assingment with message "error: lvalue required as left operand of assignment".
	// return_rvalue() = 10;
	// Valid assignment because function returning lvalue.
	return_lvalue() = 10;
}


