#include "gfnumber.h"
#include "gfield.h"

GFNumber::GFNumber()
{
    this->field = new GField();
}

GFNumber::GFNumber(uint64_t bits)
{
    this->bits = bits;
    this->field = new GField();
}

GFNumber *GFNumber::getCopy()
{
    GFNumber* copy = new GFNumber(bits);
    // TODO fill with rest of copying - field, etc.
    return copy;
}

std::string GFNumber::toString()
{
    std::stringstream ss = std::stringstream();
    bool firstXReached = false;
    for(int i = 63; i >= 0; i--)
        if (bits & ((uint64_t)1 << i)) // if bit i is set
        {
            if(!firstXReached)
            {
                ss << "x^" << i;
                firstXReached = true;
            }
            else
            {
                ss << " + x^" << i;
            }
        }
    return ss.str();
}

uint64_t GFNumber::getBits() const
{
    return bits;
}

uint8_t GFNumber::getDegree()
{
    for(int i = 63; i > 0; i--)
        if (bits & ((uint64_t)1 << i)) // if bit i is set
            return i;
    return 0;
}

GFNumber GFNumber::operator*(GFNumber b)
{
    return this->field->Multiply(*this,b);
}
