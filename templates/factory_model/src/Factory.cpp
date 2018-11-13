#include <utility>
#include <map>
#include <string>
#include <map>

#include "Factory.h"
std::map<std::string, factoryMethod> Factory::registeredModules;

bool Factory::registerModule(std::string name, factoryMethod createMethod) {
    Factory::registeredModules[Factory::traslateModuleName(name)] = createMethod;
    return true;
}

Base *Factory::create(std::string name) {
    for (auto &registeredModule : registeredModules) {
        if (name == registeredModule.first) {
            return registeredModule.second();
        }
    }
    return nullptr;
}

std::vector<std::string> Factory::getRegisteredModules() {
    std::vector<std::string> modules;
    for (auto &module : registeredModules) {
        modules.push_back(module.first);
    }
    return modules;
}

bool Factory::isRegisteredModule(std::string &name) {
    for (auto &module : registeredModules) {
        if (name == module.first) {
            return true;
        }
    }
    return false;
}

std::string Factory::traslateModuleName(std::string name) {
    while (name.size() && name[0] >= '0' && name[0] <= '9') {
        name.erase(name.begin());
    }
    return name;
}
