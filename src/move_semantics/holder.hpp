#ifndef HOLDER_HPP
#define HOLDER_HPP

#include <cstddef>

class Holder
{
public:
    Holder(int size);
    Holder(const Holder& other);
    ~Holder();
private:
    int* m_data;
    size_t m_size;
};

#endif
