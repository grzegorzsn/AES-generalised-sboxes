#ifndef GFNUMBER_H
#define GFNUMBER_H
#include <bitset>
using namespace std;

/// \var BITSET_LEN
/// This constatn defines number of bits used to store numbers (polynomials) belonging to Galois Fields.
const uint8_t BITSET_LEN = 16;


/// \typedef GFNumber
/// Type created to store numbers (polynomials) beloning to Galois Fields.
/// It is based on bitset as it provides flexible operations on particular bits.
typedef bitset<BITSET_LEN> GFNumber;

#endif // GFNUMBER_H
