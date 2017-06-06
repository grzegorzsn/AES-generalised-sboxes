#ifndef SBOX_H
#define SBOX_H

#include "galoisfield.h"
#include <vector>

/*!
 * Class representing S-Box.
 */
class SBox
{
public:
    /*!
     * \brief Default constructor.
     */
    SBox();

    /*!
     * \brief Constructor, which sets modulus of Galois Field used to compute S-Box values.
     */
    SBox(GFNumber modulus);

    /*!
     * \brief Sets modulus of Galois Field used to compute S-Box values.
     */
    void setModulus(GFNumber modulus);

    /*!
     * \brief Returns output of S-Box for passed input.
     */
    GFNumber substitute(GFNumber a);

    /*!
     * \brief Returns full substitution table of S-Box.
     */
    std::vector<GFNumber> substitutionTable();
private:
    GFNumber modulus;
    GFNumber trim(GFNumber a, int8_t degree = 8);
    uint8_t rotate(uint8_t a);
    GFNumber affineTransformation(GFNumber a);
};

#endif // SBOX_H
