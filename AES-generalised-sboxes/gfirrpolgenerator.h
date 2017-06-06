#ifndef GFIRRPOLGENERATOR_H
#define GFIRRPOLGENERATOR_H

#include <vector>
#include "galoisfield.h"

/*!
 * This class provides mechanism for generation irreducible polynomials.
 * Used algorithm is based on the same concept as Eratostenes sieve.
 * All polynomials with degree less or equal to provided max degree are considered, when algorithm starts.
 * Polynomials, which are products of other polynomials are crossed out.
 * After this operations only irreducible polynomials are left in the vector.
 *
 */
class GFIrrPolGenerator // irreducible polynomial generator
{
public:
    /*!
     * \brief Constructor.
     */
    GFIrrPolGenerator();

    /*!
     * \brief Returns generated irreducbile polynomials.
     */
    std::vector<GFNumber> generate();

    /*!
     * \brief Returns set max degree.
     */
    uint8_t getMaxDegree() const;

    /*!
     * \brief Allows to set max degree of polynomials, which are searched.
     */
    void setMaxDegree(const uint8_t &value);

protected:
    uint8_t maxDegree;
    GaloisField gf;
};

#endif // GFIRRPOLGENERATOR_H
