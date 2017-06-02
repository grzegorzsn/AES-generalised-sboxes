#ifndef NONLINEARITY_H
#define NONLINEARITY_H
#include <bitset>
#include <vector>
#include "sbox.h"

using namespace std;

typedef bitset<8> Function;

struct Coverage
{
    Function function;
    int coverage;
};

typedef vector<Coverage> Approximation;

class NonLinearity
{
public:
    NonLinearity();
    int calucalate(SBox sbox);
private:
    Approximation approximation;
    bool sboxCorrect(SBox sbox);
    bool computeFunction(Function f, GFNumber input);
    int computeCoverage(SBox sbox, uint8_t outputPosition, Function f);

};

#endif // NONLINEARITY_H
