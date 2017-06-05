#ifndef NONLINEARITY_H
#define NONLINEARITY_H
#include "sbox.h"
#include <math.h>


class NonLinearity
{

public:
    double compute();
    NonLinearity(SBox sbox);
protected:
    SBox sbox;
    vector<GFNumber> substitionTable;
    double WHTValue(GFNumber k, int u);
    double PARValue();
    int innerProduct(GFNumber a, GFNumber b);
};

#endif // NONLINEARITY_H
