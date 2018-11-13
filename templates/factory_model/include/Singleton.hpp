#include <string>

#include "Base.h"
#include "Singleton.h"

template<typename TInstance>
std::string Singleton<TInstance>::name = Factory::traslateModuleName(typeid(TInstance).name());

template<typename TInstance>
bool Singleton<TInstance>::registered = Factory::registerModule(Singleton<TInstance>::name, Singleton<TInstance>::create);

template<typename TInstance>
Base *Singleton<TInstance>::create() {
    static TInstance instance;
    return &instance;
}

template<typename TInstance>
void Singleton<TInstance>::initialize() {
    lock.try_lock();
}

template<typename TInstance>
std::string Singleton<TInstance>::getName() {
    return TInstance::name;
}

template<typename TInstance>
bool Singleton<TInstance>::isRegistered() {
    return true;
    return registered;
}

template<typename TInstance>
void Singleton<TInstance>::finish() {
    lock.unlock();
    return;
}

template<typename TInstance>
bool Singleton<TInstance>::deleteRequired() {
    return false;
}
