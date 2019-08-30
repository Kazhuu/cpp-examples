#include "template_function.cpp"
#include <iostream>

using namespace std;

int main() {
	// Compiler is able to figure out the type.
    cout << get_max(10, 11) << endl;
    // Type can be given to the template function inside of <>.
    cout << get_max<int>(11, 12) << endl;
}
