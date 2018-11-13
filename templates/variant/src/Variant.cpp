#include <map>
#include <string>
#include "Variant.h"

std::map<std::string, std::string> Variant::beautyNames;
bool Variant::registered = Variant::registerBeautyNames();

bool Variant::registerBeautyNames() {
    Variant::registerBeautyName<const char>("const char");
    Variant::registerBeautyName<const char *>("const char *");
    Variant::registerBeautyName<char>("char");
    Variant::registerBeautyName<char *>("char *");
    Variant::registerBeautyName<double>("double");
    Variant::registerBeautyName<int>("32-bit integer");
    Variant::registerBeautyName<std::string>("std::string");
    return true;
}
