#include <memory> // smart pointers
#include <iostream>

using namespace std;

int main() {
	// Make from raw pointer.
	unique_ptr<int> int_ptr1(new int(10));
	cout << "int_ptr1: " << *int_ptr1 << endl;
	// Array pointer each cell initialized to zero.
	unique_ptr<int []> int_ptr2(new int[10]());
	cout << "int_ptr2[0]: " << int_ptr2[0] << endl;
	// Use of std::make_unique<>() function, prefer this.
	unique_ptr<int> int_ptr3 = make_unique<int>(20);
	cout << "int_ptr3: " << *int_ptr3 << endl;
}
