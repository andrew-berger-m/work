#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <string>
#include <typeinfo>
#include <mutex>

#include "Base.h"
#include "Factory.h"

template<typename TInstance>
class Singleton : public Base {
public:
    static Base *create();
    std::string getName();
    bool isRegistered();

    virtual void initialize();
    virtual void finish();
    bool deleteRequired();

    Singleton<TInstance>& operator=(Singleton<TInstance> const&) = delete;

private:
    static bool registered;
    static std::string name;
    std::mutex lock;
};

#include "Singleton.hpp"

#endif  // SINGLETON_H_
