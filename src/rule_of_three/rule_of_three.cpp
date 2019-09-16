// Example based on this blog post:
// https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners

/*
 * Rule of three states that if your class manages memory itself or defines one
 * of the following it should probably define all three. These three are
 * destructor, copy constructor and copy assignment operator. Reason for this is
 * that probably in this case default compiler generated version is not enough
 * to do the job.
 *
 * Above rule is valid prior C++11. With C++11 move semantics were introduced
 * and rule was expanded to rule of five.
 */
#include "holder.hpp"

int main()
{
    Holder holder1(10); // Regular constructor.

    Holder holder2 = holder1; // Copy constructor called.
    Holder Holder3(holder1); // Copy constructor alternative syntax.

    Holder holder3(300); // Regular constructor.
    Holder holder4(400); // Regular consturctor.
    holder3 = holder4; // Assignment operator.
}
