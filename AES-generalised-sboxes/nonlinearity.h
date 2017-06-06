#ifndef NONLINEARITY_H
#define NONLINEARITY_H
#include "sbox.h"
#include <math.h>

/*!
 *  This class provides mechanism for non linearity caluclation for provided 8x8 S-Box.
 *  Calculation are based on following document:
 *
 * Generalised S-Box Nonlinearity <br>
 * NES/DOC/UIB/WP5/020/A <br>
 * Matthew G. Parker 1 2 <br>
 * Institute for Informatics,<br>
 * University of Bergen, Norway <br>
 *
 * <a href="http://www.ii.uib.no/~matthew/SBoxLin.pdf">www.ii.uib.no/~matthew/SBoxLin.pdf</a>
 *
 */
class NonLinearity
{

public:

    /*!
     * Computes and returns value of non linearity.
     * <img align="left" src="nl.png" />
     */
    double compute();

    /*!
     * \brief Constructor needs S-Box, which non linearity will be measured.
     */
    NonLinearity(SBox sbox);
protected:
    SBox sbox;
    vector<GFNumber> substitionTable;

    /*!
     * Returns value of Walsh–Hadamard transform for provided k and u.
     * U is a position of considered output bit.
     * <img align="left" src="wht.png" />
     */
    double WHTValue(GFNumber k, int u);

    /*!
     * Returns value of Peak-to-Average Power Ratio (PAR).
     * <img align="left" src="par.png" />
     */
    double PARValue();

    /*!
     * Returns value of inner product of two provided numbers.
     * <img align="left" src="inner.png" />
     */
    int innerProduct(GFNumber a, GFNumber b);
};

#endif // NONLINEARITY_H
