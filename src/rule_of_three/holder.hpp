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
     * Copy assignment operator takes existing object and copies it's content to
     * the this existing object. Original other object is left untouched.
     */
    Holder& operator=(const Holder& other);
    // Implement custom destructor to delete your own managed memory.
    ~Holder();
private:
    int* m_data;
    size_t m_size;
};

#endif
