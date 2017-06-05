#include "function.h"



Function::Function(bitset<8> _coeficient)
{
    Function(_coeficient, false);
}

Function::Function(bitset<8> _coeficient, bool _negation)
{
    coeficients = _coeficient;
    negation = _negation;
}

bool Function::compute(GFNumber x)
{
    throw logic_error("Unimplemented");
    return false;
}
