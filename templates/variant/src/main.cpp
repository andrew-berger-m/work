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
    Variant test[10];

    test[0] = true;
    test[1] = 234u;
    test[2] = (short)((unsigned int)test[1] + 1000);
    test[3] = test[2];
    test[4] = std::string("It is sunny day.");
    test[5] = "And one more nice day.";
    test[6] = 3.14;
    demo myDemo = { "Bad day is today!", true, 777 };
    test[7] = myDemo;
    test[8] = test[7];
    test[8].getValuePtr<demo>()->parameter1 = "Lovely day is today!";
    myDemo.parameter3 = 333;  //  no effect, Variant is holding copy of struct
    test[9] = &myDemo;

    std::cout << "Output of the test:" << std::endl;
    for (unsigned int i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
        std::cout << "test[" << i << "] has value '" << test[i]
                  << "' and has beauty name '"
                  << test[i].getBeautyName() << "'" <<  std::endl;
    }

    return 0;
}
