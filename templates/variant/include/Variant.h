#include <map>
#include <string>
#include <typeinfo>
#include <memory>

#ifndef VARIANT_H_
#define VARIANT_H_

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
    void setValue(const Type value)
    {
        name = typeid(Type).name();
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

    const std::string getClassName()
    {
        return name;
    }

    template<typename Type>
    static void registerBeautyName(const std::string &beautyName)
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

    private:
        Type value;
    };

    std::shared_ptr<AbstractValueWrapper> value;
    std::string name;
    static std::map<std::string, std::string> beautyNames;
    static bool registered;
};

#endif // VARIANT_H_
