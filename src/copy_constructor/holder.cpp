#include "holder.hpp"
#include <algorithm>
#include <iostream>

Holder::Holder(int size)
{
    std::cout << "constructor called" << std::endl;
    m_data = new int[size];
    m_size = size;
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

Holder::~Holder()
{
    delete[] m_data;
}
