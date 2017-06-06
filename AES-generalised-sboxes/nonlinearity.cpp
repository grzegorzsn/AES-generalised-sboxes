#include "nonlinearity.h"

// Implementation of equation nr 7
double NonLinearity::compute()
{
    int n = 8;
    return pow(2.0, n / 2 - 1) * ((pow(2.0, n/2) - sqrt(PARValue())));
}

NonLinearity::NonLinearity(SBox _sbox)
{
    sbox = _sbox;
    substitionTable = sbox.substitutionTable();
}

// Implementation of equation nr 2
double NonLinearity::WHTValue(GFNumber k, int u)
{
    int sum = 0;
    for(int x = 0; x < 256; x++)
    {
        int exponent = int(substitionTable[x][u]) + innerProduct(GFNumber(x), k);
        sum += pow(-1.0, exponent);
    }
    return pow(2.0, -8.0) * sum;
}

// Implementation of equation nr 5
double NonLinearity::PARValue()
{
    double max = WHTValue(GFNumber(0), 0);
    for(int u = 0; u < 8; u++)
        for(int k = 0; k < 256; k++)
        {
            double Fk = WHTValue(GFNumber(k), u);
            if(Fk > max) max = Fk;
        }
    return pow(2.0, 8.0) * pow(max, 2.0);
}

int NonLinearity::innerProduct(GFNumber a, GFNumber b)
{
    GFNumber logicAnd = a&b;
    return logicAnd.count();
}
