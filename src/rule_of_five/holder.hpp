#ifndef HOLDER_HPP
#define HOLDER_HPP

#include <cstddef>

class Holder
{
public:
    Holder(int size);
    /*
     * Copy constructor takes another object of the same type as its first
     * parameter and is used to copy its content to the newly created object by
     * this constructor. Original other object is left untouched.
     */
    Holder(const Holder& other);
    /*
     * Move constructor takes a temporary object as an rvalue reference and
     * move/steals data from it to newly created object without making copies.
     * After data has been moved, other object should be left in well defined
     * state.
     */
    Holder(Holder&& other);
    /*
     * Copy assignment operator takes existing object and copies it's content to
     * the this existing object. Original other object is left untouched.
     */
    Holder& operator=(const Holder& other);
    /*
     * Move assignment operator takes a temporary object as an rvalue reference
     * and move/steals data from it to the this object. This object's data is
     * deleted and data is moved from the other object. Other object should be
     * left in well defined stated after.
     */
    Holder& operator=(Holder&& other);
    // Implement custom destructor to delete your own managed memory.
    ~Holder();
private:
    int* m_data;
    size_t m_size;
};

#endif
