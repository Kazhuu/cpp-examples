#include <string>
#include <vector>
#include <iostream>

/*
 * Prefer using C++ alias declarations over typedefs. Examples are taken from
 * the book Effective Modern C++ by Scott Meyers from item 9.
 */

void f(std::string name)
{
    std::cout << "f(name): " << name << std::endl;
}

// Alias template.
template<typename T>
using MyUsingList = std::vector<T>;

// Same as above but hacked together using typedef.
template<typename T>
struct MyTypedefList {
    typedef std::vector<T> type;
};

/*
 * If typedef hacked template type needs to take another template parameter,
 * then it will become dependant type, thus requiring typename keyword and
 * ::type preceding variable name. These are not needed with alias templates.
 */
template<typename T>
struct DependantTypeStruct {
    typename MyTypedefList<T>::type struct_field;
};

// Same as above can be achieved easier when using alias template instead.
// Notice no need for typename keyword or ::type preceding variable name.
template<typename T>
struct AliasTemplateStruct {
    MyUsingList<int> struct_field;
};

int main()
{
    // Easier to understand function pointers. Both cases are equivalent. Both
    // cases have function pointer to function that is returning void and taking
    // string as one parameter.
    typedef void (*TYPEDEF_FP)(std::string);
    TYPEDEF_FP typedef_fp = f;
    typedef_fp("typedef function pointer");

    using USING_FP = void (*)(std::string);
    USING_FP using_fp = f;
    using_fp("alias function pointer");

    /*
     * Alias declarations can be used with templates so they can be templatized.
     * In this case they are called alias templates. Achieving same with
     * typedefs usually requires some hacks to achieve the same.
     */
    // Variable using alias template.
    MyUsingList<int> myList1;
    // Variable using same but with typedefs.
    MyTypedefList<int>::type myList2;
    // This seems okay but check when RandomStruct is used, it's struct_field
    // variable becomes dependant type and typename keyword and ::type are
    // required. These are not needed with alias templates.
    DependantTypeStruct<int> myList3;
    // Better solution is to use alias template struct instead.
    AliasTemplateStruct<int> myList4;
}
