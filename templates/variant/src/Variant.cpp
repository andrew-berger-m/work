//  extended class with no license

#include <string>
#include "Variant.h"

std::map<std::string, std::string> Variant::beautyNames;
bool Variant::registered = Variant::registerBeautyNames();

bool Variant::registerBeautyNames() {
    Variant::registerbeautyName<char>("char");
    Variant::registerbeautyName<signed char>("signed char");
    Variant::registerbeautyName<unsigned char>("unsigned char");
    Variant::registerbeautyName<int>("signed int");
    Variant::registerbeautyName<unsigned int>("unsigned int");
    Variant::registerbeautyName<long>("signed long");
    Variant::registerbeautyName<unsigned long>("unsigned long");
    Variant::registerbeautyName<short>("signed short");
    Variant::registerbeautyName<unsigned short>("unsigned short");
    Variant::registerbeautyName<float>("float");
    Variant::registerbeautyName<double>("double");
    Variant::registerbeautyName<bool>("boolean");
    Variant::registerbeautyName<char*>("char *");
    Variant::registerbeautyName<signed char*>("signed char *");
    Variant::registerbeautyName<unsigned char*>("unsigned char *");
    Variant::registerbeautyName<const char*>("const char *");
    Variant::registerbeautyName<const signed char*>("const signed char *");
    Variant::registerbeautyName<const unsigned char*>("const unsigned char *");
    Variant::registerbeautyName<std::string>("string");
    Variant::registerbeautyName<const std::string>("string");
    Variant::registerbeautyName<demo>("struct demo");
    return true;
}

std::ostream& operator << (std::ostream& os, Variant variant) {
    if (variant.getClassName() == "d") {
        os << (double)variant.getValue<double>();
    } else if (variant.getClassName() == "Kd") {
        os << (const double)variant.getValue<double>();
    } else if (variant.getClassName() == "f") {
        os << (float)variant.getValue<float>();
    } else if (variant.getClassName() == "Kf") {
        os << (const float)variant.getValue<const float>();
    } else if (variant.getClassName() == "i") {
        os << (int)variant.getValue<int>();
    } else if (variant.getClassName() == "j") {
        os << (unsigned int)variant.getValue<unsigned int>();
    } else if (variant.getClassName() == "l") {
        os << (long)variant.getValue<long>();
    } else if (variant.getClassName() == "m") {
        os << (unsigned long)variant.getValue<unsigned long>();
    } else if (variant.getClassName() == "x") {
        os << (long long)variant.getValue<long long>();
    } else if (variant.getClassName() == "y") {
        os << (unsigned long long)variant.getValue<unsigned long long>();
    } else if (variant.getClassName() == "s") {
        os << (short)variant.getValue<short>();
    } else if (variant.getClassName() == "t") {
        os << (unsigned short)variant.getValue<unsigned short>();
    } else if (variant.getClassName() == "c") {
        os << (char)variant.getValue<char>();
    } else if (variant.getClassName() == "a") {
        os << (signed char)variant.getValue<signed char>();
    } else if (variant.getClassName() == "h") {
        os << (unsigned char)variant.getValue<unsigned char>();
    } else if (variant.getClassName() == "b") {
        os << ((bool)variant.getValue<bool>() == false ? "false" : "true");
    } else if (variant.getClassName() == "Pc") {
        os << (char *)variant.getValue<char *>();
    } else if (variant.getClassName() == "Pa") {
        os << (signed char *)variant.getValue<signed char *>();
    } else if (variant.getClassName() == "Ph") {
        os << (unsigned char *)variant.getValue<unsigned char *>();
    } else if (variant.getClassName() == "PKc") {
        os << (const char *)variant.getValue<const char *>();
    } else if (variant.getClassName() == "PKa") {
        os << (const signed char *)variant.getValue<const signed char *>();
    } else if (variant.getClassName() == "PKh") {
        os << (const unsigned char *)variant.getValue<const unsigned char *>();
    } else if (variant.getClassName() == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE") {
        os << variant.getValue<std::string>();
    } else if (variant.getClassName() == "demo") {
        os << "{ DEMO: "
           << variant.getValue<demo>().parameter1 << ", "
           << variant.getValue<demo>().parameter2 << ", "
           << variant.getValue<demo>().parameter3
           << " }";
    } else {
        os << "Default conversion is not implemented for '" << variant.getClassName() << "'";
    }
    return os;
}
