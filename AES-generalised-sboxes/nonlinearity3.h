#ifndef NONLINEARITY3_H
#define NONLINEARITY3_H
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

class NonLinearity3
{
public:
    NonLinearity3();
    int calucalate(SBox sbox);
private:
    Approximation approximation;
    bool sboxCorrect(SBox sbox);
    bool computeFunction(Function f, GFNumber input);
    int computeCoverage(SBox sbox, uint8_t outputPosition, Function f);

};

#endif // NONLINEARITY3_H
