#include "holder.hpp"
#include <algorithm>

Holder::Holder(int size)
{
    m_data = new int[size];
    m_size = size;
}

Holder::Holder(const Holder& other)
{
    m_data = new int[other.m_size];
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
    m_size = other.m_size;
}

Holder::~Holder()
{
    delete[] m_data;
}
