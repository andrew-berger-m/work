#include <string>

#include "Base.h"
#include "Multiton.h"

template<typename TInstance>
std::string Multiton<TInstance>::name = Factory::traslateModuleName(typeid(TInstance).name());

template<typename TInstance>
bool Multiton<TInstance>::registered = Factory::registerModule(TInstance::name, &Multiton<TInstance>::create);

template<typename TInstance>
Base *Multiton<TInstance>::create() {
    TInstance *instance = new TInstance;
    return instance;
}

template<typename TInstance>
void Multiton<TInstance>::initialize() {
}

template<typename TInstance>
std::string Multiton<TInstance>::getName() {
    return TInstance::name;
}

template<typename TInstance>
bool Multiton<TInstance>::isRegistered() {
    return registered;
}

template<typename TInstance>
void Multiton<TInstance>::finish() {
    delete this;
}

template<typename TInstance>
bool Multiton<TInstance>::deleteRequired() {
    return true;
}
