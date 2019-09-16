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

Holder::Holder(Holder&& other)
{
    std::cout << "move constructor called" << std::endl;
    // Assign other object data pointer to this object. No copies.
    m_data = other.m_data;
    // Same with size member variable.
    m_size = other.m_size;
    // Set other object to well defined state like setting pointer to nullptr
    // etc.
    other.m_data = nullptr;
    other.m_size = 0;
}

Holder& Holder::operator=(const Holder& other)
{
    std::cout << "copy assignment operator called" << std::endl;
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

Holder& Holder::operator=(Holder&& other)
{
    std::cout << "move assignment operator called" << std::endl;
    // Protect against self assignment like in the copy assignment operator
    // above.
    if (this == &other)
    {
        return *this;
    }
    // Clean up this objects data.
    delete[] m_data;
    // Move data to the this object like in move constructor.
    m_data = other.m_data;
    m_size = other.m_size;
    // Leave other object in well defined state afterwards.
    other.m_data = nullptr;
    other.m_size = 0;
    // Return this object.
    return *this;
}

Holder::~Holder()
{
    std::cout << "destructor called" << std::endl;
    delete[] m_data;
}
