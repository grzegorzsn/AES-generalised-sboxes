#ifndef GFIELD_H
#define GFIELD_H
#include <bitset>
#include <sstream>
using namespace std;

const uint8_t BITSET_LEN = 64;
typedef bitset<BITSET_LEN> GFNumber;

class GaloisField
{
public:
    GaloisField();
    bool InField(bitset<64> a);
    GFNumber Multiply(GFNumber a, GFNumber b);
    string display(GFNumber bits);
    uint8_t degree(GFNumber bits);
    GFNumber getModulus();
    void setModulus(bitset<64> value);

protected:
    GFNumber modulus;
};

#endif // GFIELD_H
