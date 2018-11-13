#include <iostream>
#include <map>
#include <string>
#include "Variant.h"
/*
This program will demonstrate my basic implementation of Variant class via templates.
The Problem: You can also store value into type of (void *), but, how will you deallocate memory, if value will be not needed anymore?
The Problem: Keeping information about value type stored in type of (void *) is verbose operation in your code.
My Variant class is a container holding value by shared pointer, and destructor will be called, if value will be not needed.
The class also knows some data types, so you could ask for beauty name of type stored in the Variant class.
If beauty name is not registered, you will get current name of stored type.
*/

int main()
{
    Variant test1, test2, test3, test4, test5;

    test1 = 7;
    test2 = (int)test1 * 2.2;
    test3 = "It is nice to have.";
    test4 = 'c';
    test5 = std::string("Sunny day. ") + (char *)test3;

    std::cout << "Variant test1 has value: '" << (int)test1 << "' and is type of '" << test1.getBeautyName() << "'" << std::endl;
    std::cout << "Variant test2 has value: '" << (double)test2 << "' and is type of '" << test2.getBeautyName() << "'" << std::endl;
    std::cout << "Variant test3 has value: '" << (const char *)test3 << "' and is type of '" << test3.getBeautyName() << "'" << std::endl;
    std::cout << "Variant test4 has value: '" << (char)test4 << "' and is type of '" << test4.getBeautyName() << "'" << std::endl;
    std::cout << "Variant test5 has value: '" << (std::string)test5 << "' and is type of '" << test5.getBeautyName() << "'" << std::endl;
    std::cout << "Variant test1 has wrong value: '" << (char)test1 << "' because is type of '" << test1.getBeautyName() << "'" << std::endl;
    return 0;
}

