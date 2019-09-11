#include "holder.hpp"
#include <algorithm>
#include <iostream>

Holder::Holder(int size)
{
    std::cout << "constructor called" << std::endl;
    m_data = new int[size];
    m_size = size;
}

Holder::~Holder()
{
    std::cout << "destructor" << std::endl;
    delete[] m_data;
}

Holder::Holder(const Holder& other)
{
    std::cout << "copy constructor called" << std::endl;
    // Initialize array of the same size.
    m_data = new int[other.m_size];
    // Copy data as is from other object to this new object.
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
    // Also copy size interger.
    m_size = other.m_size;
}

Holder& Holder::operator=(const Holder& other)
{
    std::cout << "copy assignment operator" << std::endl;
    // If other points to the same object then return this object instead.
    // This protects agains self assignment like holder1 = holder1;
    if (this == &other) {
        return *this;
    }
    // Delete original data from this object.
    delete[] m_data;
    // Reserve memory amount of other data to be copied.
    m_data = new int[other.m_size];
    // Copy the data from other object to the this object.
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
    m_size = other.m_size;
    // Return this object.
    return *this;
}
