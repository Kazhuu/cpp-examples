// Example based on this blog post:
// https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners

/*
 * Rule of three was expanded to rule of five when C++11 introduced move
 * semantics. Same rules apply as to rule of three but additionally class has to
 * implement move constructor and move assignment operator which both takes other
 * object as rvalue reference (annotated with double ampersand after type
 * Object&&). Move semantics helps to optimize code by moving allocated data
 * between objects rather than making copies of it.
 */
#include "holder.hpp"
#include <memory>

/*
 * Function to test move semantics with Holder object. Function returns Holder
 * object by value. If move semantics were not used when created temporary
 * rvalue object is returned, copy of the returned object will be created.  When
 * calling this function without move semantics, two memory allocations will
 * happen inside of Holder object. One when temporary object is created inside
 * of function and when returned rvalue is copied with copy constructor or copy
 * assignment operator in callee code. With move semantics compiler will assign
 * code to call move constructor or move assign operator instead. With this
 * expensive copy operation will not happen.
 */
Holder createHolder(int size)
{
    return Holder(size);
}

int main()
{
    Holder holder1(10); // Regular constructor.
    Holder holder2(holder1); // Copy constructor (lvalue in input).
    Holder holder3 = createHolder(30); // Move constructor (rvalue in input).
    // With above line compiler will call normal constructor because of return
    // value optimization (RVO). This optimization can be bypassed with
    // -fno-elide-constructor flag.

    holder2 = holder3; // Copy assignment operator (lvalue in input).
    holder3 = createHolder(30); // Move assignment operator (rvalue in input).

    /*
     * To move data from an lvalue object std::move() has to be used to tell to
     * function call that an rvalue is passed as an argument and it will trigger
     * move constructor/move assignment operator call instead. std::move() will
     * convert lvalue to the rvalue.
     */
    Holder holder4(400);
    Holder holder5(holder4); // Copy constructor because of the lvalue as an argument.
    Holder holder6(std::move(holder5)); // Move constructor because of the rvalue (std::move()).
}
