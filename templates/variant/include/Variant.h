//  extended class with no license

#include <map>
#include <string>
#include <typeinfo>
#include <memory>
#include <ostream>

#ifndef VARIANT_H_
#define VARIANT_H_

// remove the struct later
struct demo {
    const char *parameter1;
    bool parameter2;
    unsigned long long parameter3;
};

class Variant
{
public:
    Variant() {
    }

    template<class Type>
    Variant(const Type value)
    {
        setValue<Type>(value);
    }

    template<class Type>
    const Type getValue()
    {
        return static_cast<ValueWrapper<Type>*>(value.get())->getValue();
    }

    template<class Type>
    Type *getValuePtr()
    {
        return static_cast<ValueWrapper<Type>*>(value.get())->getValuePtr();
    }

    template<class Type>
    void setValue(const Type value)
    {
        name = typeid(Type).name();
        isArithmetic = std::is_arithmetic<Type>();
        isScalar = std::is_scalar<Type>();
        this->value = std::make_shared<ValueWrapper<Type>>(ValueWrapper<Type>(value));
    }

    template<typename Type>
    void operator =(const Type value)
    {
        setValue<Type>(value);
    }

    template<typename Type>
    explicit operator Type()
    {
        return getValue<Type>();
    }

    std::string getClassName()
    {
        return traslateClassName(name);
    }

    template<typename Type>
    static void registerbeautyName(const std::string &beautyName)
    {
        beautyNames[typeid(Type).name()] = beautyName;
    }

    static bool registerBeautyNames();

    const std::string getBeautyName()
    {
        std::map<std::string, std::string>::iterator it;
        if ((it = beautyNames.find(name)) != beautyNames.end()) {
            return it->second;
        }
        return name;
    }

private:
    struct AbstractValueWrapper
    {
        virtual ~AbstractValueWrapper() = default;
    };

    template<class Type>
    class ValueWrapper : public AbstractValueWrapper
    {
    public:
        ValueWrapper(const Type value) : value(value) { }
        virtual ~ValueWrapper() {}
        Type getValue() { return value; }
        Type *getValuePtr() { return &value; }

    private:
        Type value;
    };

    std::string traslateClassName(std::string name) {
        while (name.size() && ((name[0] >= '0' && name[0] <= '9') || name[0] == 'K')) {
            name.erase(name.begin());
        }
        return name;
    }

    std::shared_ptr<AbstractValueWrapper> value;
    std::string name;
    bool isArithmetic;
    bool isScalar;
    static std::map<std::string, std::string> beautyNames;
    static bool registered;
};

std::ostream& operator << (std::ostream& os, Variant variant);

#endif // VARIANT_H_
