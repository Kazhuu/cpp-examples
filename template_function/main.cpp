#include "template_function.cpp"
#include <iostream>

using namespace std;

int main() {
    cout << get_max(10, 11) << endl;
    cout << get_max<int>(11, 12) << endl;
}

