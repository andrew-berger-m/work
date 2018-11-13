#ifndef BASE_H_
#define BASE_H_

#include <string>
#include <vector>

class Base {
public:
    Base();
    virtual ~Base();

public:
    //  overriden by templates
    virtual bool isRegistered() = 0;
    virtual std::string getName() = 0;
    virtual void finish() = 0;

    virtual std::string ping();
    virtual bool deleteRequired();
};

#endif  // BASE_H_
