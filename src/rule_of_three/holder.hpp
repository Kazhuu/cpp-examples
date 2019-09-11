#ifndef HOLDER_HPP
#define HOLDER_HPP

#include <cstddef>

/*
 * Rule of three states that if your class manages memory itself or defines one
 * of the following it should probably define all three. These three are
 * destructor, copy constructor and copy assignment operator. Reason for this is
 * that probably in this case default compiler generated version is not enough
 * to do the job.
 */
class Holder
{
public:
    Holder(int size);
    // Implement custom destructor to delete your own managed memory.
    ~Holder();
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
private:
    int* m_data;
    size_t m_size;
};

#endif
