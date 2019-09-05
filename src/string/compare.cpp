#include <string>
#include <iostream>


int main()
{
    std::string first = "hoot";
    std::string second = "hoot1";

    std::cout << "hoot.compare(hoot1): " << first.compare(second) << std::endl;
    std::cout << "hoot1.compare(hoot): " << second.compare(first) << std::endl;
    // Take substring of hoot1 => hoot and compare it to hoot.
    std::cout << "hoot1.compare(0, 4, hoot): " << second.compare(0, 4, first) << std::endl;
}
