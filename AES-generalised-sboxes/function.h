#ifndef FUNCTION_H
#define FUNCTION_H

#include <bitset>
#include "gfnumber.h"

class Function
{
public:
    Function(bitset<8> _coeficient);
    Function(bitset<8> _coeficient,bool _negation);
    bool compute(GFNumber x);
private:
    bitset<8> coeficients;
    bool negation;
};

#endif // FUNCTION_H
