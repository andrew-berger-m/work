#include <iostream>
#include "Factory.h"

/*
 * This program demostrates working Factory class with instances of Singleton and Multiton as equivalent.
 * Strong feature is that user does not need to #include headers such are "Example1.h" anywhere in engine implemetation.
 * So, code of engine could be separated from code of modules by very easy way in your build system.
 * Code of engine: main.cpp, Multition.hpp, Singleton.hpp, Base.cpp and Factory.cpp
 * Code of modules: Example1.cpp, Example2.cpp, Example3.cpp
 */

int main() {
    Base *base1 = Factory::create("Example1");
    Base *base2 = Factory::create("Example2");

    std::cout << "Ping call from Example1 returned: '" << base1->ping() << "'" << std::endl;
    std::cout << "Ping call from Example2 returned: '" << base2->ping() << "'" << std::endl;
    std::cout << std::endl;

    base1->finish();
    base2->finish();

    std::cout << "You have registered following modules in the system:" << std::endl;
    for (auto &module : Factory::getRegisteredModules()) {
        Base *base = Factory::create(module);
        std::cout << "Module '" << base->getName() << "' returned by ping call: '" << base->ping() << "' and is alocated on " << (base->deleteRequired() ? "heap as Multiton." : "stack as Singleton.") << std::endl;
        base->finish();
    }
    return 0;
}
