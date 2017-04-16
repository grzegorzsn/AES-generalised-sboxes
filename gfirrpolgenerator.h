#ifndef GFIRRPOLGENERATOR_H
#define GFIRRPOLGENERATOR_H

#include <vector>
#include "gfnumber.h"
#include "gfield.h"
class GFIrrPolGenerator // irreducible polynomial generator
{
public:
    GFIrrPolGenerator();
    std::vector<GFNumber*> generate();

    uint8_t getMaxDegree() const;
    void setMaxDegree(const uint8_t &value);

protected:
    uint8_t maxDegree;
};

#endif // GFIRRPOLGENERATOR_H
