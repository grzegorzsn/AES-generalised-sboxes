#ifndef GFIELD_H
#define GFIELD_H
#include <sstream>
#include "gfnumber.h"
using namespace std;


/*!
 * This class provides basic operations on numbers (binary polynomials) in Galois Field.
 * Field is limitted by modulus chosen for multiplication purposes.
 * If modulus is not set, the limit is related to max length of GFNumber.
 *
 */
class GaloisField
{
public:
    /*!
     * \brief Default constructor. Modulus used in multiplication is not set.
     */
    GaloisField();

    /*!
     * \brief Constructor, which sets modulus used in multiplication.
     */
    GaloisField(GFNumber modulus);

    /*!
     * \brief Checks if provided number belongs to this field.
     */
    bool inField(GFNumber a);

    /*!
     * \brief Multiplies two numbers.
     */
    GFNumber multiply(GFNumber a, GFNumber b);

    /*!
     * \brief Divides a by b.
     */
    GFNumber divide(GFNumber a, GFNumber b);

    /*!
     * \brief Computes a modulo b.
     */
    GFNumber modulo(GFNumber a, GFNumber b);

    /*!
     * \brief Computes multiplicative inverse of number a in this field.
     */
    GFNumber multiplicativeInverse(GFNumber a);

    /*!
     * \brief Returns pretty formatet string with polynomial.
     */
    static string display(GFNumber bits);

    /*!
     * \brief Returns degree of provided polynomial.
     */
    static int8_t degree(GFNumber bits);

    /*!
     * \brief Returns modulus used in this field for multiplication purposes.
     */
    GFNumber getModulus();

    /*!
     * \brief Allows to set polynomial used for multiplication purposes.
     */
    void setModulus(GFNumber value);

protected:
    GFNumber multiplyWithoutModulo(GFNumber a, GFNumber b);
    GFNumber modulus;
};

#endif // GFIELD_H
