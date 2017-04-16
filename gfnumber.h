#ifndef GFNUMBER_H
#define GFNUMBER_H

#include <stdint.h>
#include <string>
#include <sstream>

class GField;

class GFNumber
{
public:
    GFNumber();
    GFNumber(uint64_t bits);
    GFNumber *getCopy();
    std::string toString();
    uint64_t getBits() const;
    uint8_t getDegree();
    GFNumber operator*(GFNumber b);

protected:
    uint64_t bits; //TODO refactor type to bitset
    GField *field;

};

#endif // GFNUMBER_H
