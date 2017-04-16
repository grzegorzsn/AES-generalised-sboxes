#ifndef GFIRRPOLGENERATOR_H
#define GFIRRPOLGENERATOR_H

#include <vector>
#include "galoisfield.h"
class GFIrrPolGenerator // irreducible polynomial generator
{
public:
    GFIrrPolGenerator();
    std::vector<bitset<BITSET_LEN>> generate();

    uint8_t getMaxDegree() const;
    void setMaxDegree(const uint8_t &value);

protected:
    uint8_t maxDegree;
    GaloisField gf;
};

#endif // GFIRRPOLGENERATOR_H
