#ifndef FACTORY_H_
#define FACTORY_H_

#include <string>
#include <vector>
#include <map>

#include "Base.h"

typedef Base* (*factoryMethod)();

class Factory {
public:
    static bool registerModule(std::string name, factoryMethod createMethod);
    static Base *create(std::string name);
    static std::vector<std::string> getRegisteredModules();
    static bool isRegisteredModule(std::string &name);
    static std::string traslateModuleName(std::string name);

private:
    static std::map<std::string, factoryMethod> registeredModules;
};

#endif  // FACTORY_H_
