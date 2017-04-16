#ifndef GFIELD_H
#define GFIELD_H
#include <bitset>
// #include "gfnumber.h"

class GFNumber;
class GField
{
public:
    GField();
    bool InField(GFNumber a);
    GFNumber Multiply(GFNumber a, GFNumber b);

    GFNumber *getModulusCopy();
    void setModulusCopy(GFNumber *value);

protected:
    GFNumber *modulus;
};

#endif // GFIELD_H
