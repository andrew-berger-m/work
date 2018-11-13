#ifndef EXAMPLE1_H
#define EXAMPLE1_H

#include "Base.h"
#include "Singleton.h"

class Example1 : public Singleton<Example1>
{
public:
    Example1();
    virtual ~Example1();

public:
    std::string ping();
};

#endif //  EXAMPLE1_H
