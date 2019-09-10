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
     * this constructor.
     */
    Holder(const Holder& other);
    ~Holder();
private:
    int* m_data;
    size_t m_size;
};

#endif
