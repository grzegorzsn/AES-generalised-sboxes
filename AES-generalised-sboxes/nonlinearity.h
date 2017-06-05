#ifndef NONLINEARITY_H
#define NONLINEARITY_H
#include "sbox.h"
#include <math.h>

/*
 *  Calculation are based on following document.
 *
 * Generalised S-Box Nonlinearity
 * NES/DOC/UIB/WP5/020/A
 * Matthew G. Parker 1 2
 * Institute for Informatics,
 * University of Bergen, Norway
 *
 * www.ii.uib.no/~matthew/SBoxLin.pdf
 *
 */

class NonLinearity
{

public:
    double compute();
    NonLinearity(SBox sbox);
protected:
    SBox sbox;
    vector<GFNumber> substitionTable;
    double WHTValue(GFNumber k, int u);
    double PARValue();
    int innerProduct(GFNumber a, GFNumber b);
};

#endif // NONLINEARITY_H
