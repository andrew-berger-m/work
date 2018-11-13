#ifndef EXAMPLE3_H
#define EXAMPLE3_H

#include "Base.h"
#include "Singleton.h"

class Example3 : public Singleton<Example3>
{
public:
    Example3();
    virtual ~Example3();

public:
    std::string ping();
};

#endif //  EXAMPLE2_H
