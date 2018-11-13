#ifndef EXAMPLE2_H
#define EXAMPLE2_H

#include "Base.h"
#include "Multiton.h"

class Example2 : public Multiton<Example2>
{
public:
    Example2();
    virtual ~Example2();

public:
    std::string ping();
};

#endif //  EXAMPLE2_H
