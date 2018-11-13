#ifndef MULTITON_H_
#define MULTITON_H_

#include <string>
#include <typeinfo>
#include <memory>

#include "Base.h"
#include "Factory.h"

template<typename TInstance>
class Multiton : public Base {
public:
    static Base *create();
    std::string getName();
    bool isRegistered();
    bool deleteRequired();

    virtual void initialize();
    virtual void finish();

private:
    static bool registered;
    static std::string name;
};

#include "Multiton.hpp"

#endif  // MULTITON_H_
