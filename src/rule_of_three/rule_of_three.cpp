// Example based on this blog post:
// https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners

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
