#include <iostream>
#include <cstdarg> // needed to use ellipsis

using namespace std;

int avarage_with_count(int count, ...) {
    double sum = 0;
    va_list vargs;
    va_start(vargs, count);

    for (int i = 0; i < count; i++) {
        sum += va_arg(vargs, int);
    }
    va_end(vargs);

    return sum / count;
}

int main() {
    cout << avarage_with_count(4, 1, 2, 3, 4) << endl;
}

