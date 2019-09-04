#include <memory> // smart pointers
#include <iostream>

// Use this definition when function assumes ownership of the smart pointer.
void take_ownership(std::unique_ptr<int> value)
{
    // Transfer ownership to local variable with std::move function.
    std::unique_ptr<int> local_var = std::move(value);
    std::cout << "take_ownership: " << *local_var << std::endl;
    // Unique pointer will be destroyed after this function.
}

int main()
{
    // Make from raw pointer.
    std::unique_ptr<int> int_ptr1(new int(10));
    std::cout << "int_ptr1: " << *int_ptr1 << std::endl;
    // Array pointer each cell initialized to zero.
    std::unique_ptr<int []> int_ptr2(new int[10]());
    std::cout << "int_ptr2[0]: " << int_ptr2[0] << std::endl;
    // Use of std::make_unique<>() function, prefer this.
    std::unique_ptr<int> int_ptr3 = std::make_unique<int>(20);
    std::cout << "int_ptr3: " << *int_ptr3 << std::endl;

    // Transfer ownership of the pointer to the function with std::move function.
    // int_ptr1 becomes null pointer after that.
    take_ownership(move(int_ptr1));
    std::cout << "int_ptr1 == nullptr: " << (int_ptr1 == nullptr) << std::endl;
}
