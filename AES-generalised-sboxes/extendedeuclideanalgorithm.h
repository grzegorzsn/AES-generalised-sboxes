#ifndef EXTENDEDEUCLIDEANALGORITHM_H
#define EXTENDEDEUCLIDEANALGORITHM_H

#include "gfnumber.h"
#include "galoisfield.h"
#include <iostream> // TODO remove
using namespace std; // TODO remove

/*
 * Description of algorithm.
 * Source: Handbook of Applied Cryptography - Alfred J. Menezes
 *
 * Extended Euclidean algorithm for Zp[x]
 * INPUT: two polynomials g(x), h(x) ∈ Zp[x].
 * OUTPUT: d(x) = gcd(g(x), h(x)) and polynomials s(x), t(x) ∈ Zp[x] which satisfy
 * s(x)g(x) + t(x)h(x) = d(x).
 * 1. If h(x) = 0 then set d(x)←g(x), s(x)←1, t(x)←0, and return(d(x),s(x),t(x)).
 * 2. Set s2(x)←1, s1(x)←0, t2(x)←0, t1(x)←1.
 * 3. While h(x) =/= 0 do the following:
 *   3.1 q(x)←g(x) div h(x), r(x)←g(x) − h(x)q(x).
 *   3.2 s(x)←s2(x) − q(x)s1(x), t(x)←t2(x) − q(x)t1(x).
 *   3.3 g(x)←h(x), h(x)←r(x).
 *   3.4 s2(x)←s1(x), s1(x)←s(x), t2(x)←t1(x), and t1(x)←t(x).
 * 4. Set d(x)←g(x), s(x)←s2(x), t(x)←t2(x).
 * 5. Return(d(x),s(x),t(x)).
 *
 */

class ExtendedEuclideanAlgorithm
{
public:
    ExtendedEuclideanAlgorithm();
    ExtendedEuclideanAlgorithm(GFNumber g, GFNumber h);
    //ExtendedEuclideanAlgorithm(GFNumber modulus);
    //ExtendedEuclideanAlgorithm(GFNumber g, GFNumber h, GFNumber modulus);
    void setInput(GFNumber g, GFNumber h);
    //void setGFModulus(GFNumber modulus);
    void compute();
    GFNumber getD();
    GFNumber getS();
    GFNumber getT();
protected:
    GFNumber g,h,d,s,t;
    GaloisField gf;
};

#endif // EXTENDEDEUCLIDEANALGORITHM_H
