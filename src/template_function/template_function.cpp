// Template function with typename keyword.
template <typename T> // "typename" can also be "class"
T get_max(T a, T b) {
    if(a < b) {
        return b;
    }
    return a;
}
