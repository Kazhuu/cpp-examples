// Template function
template <typename T>
T get_max(T a, T b) {
    if (a < b) {
        return b;
    }
    return a;
}
