#include "extendedeuclideanalgorithm.h"

ExtendedEuclideanAlgorithm::ExtendedEuclideanAlgorithm()
{
     this->gf = GaloisField();
}

ExtendedEuclideanAlgorithm::ExtendedEuclideanAlgorithm(GFNumber g, GFNumber h)
{
    this->setInput(g,h);
    this->gf = GaloisField();
}

void ExtendedEuclideanAlgorithm::setInput(GFNumber g, GFNumber h)
{
    this->g = g;
    this->h = h;
}


// Description of algorithm provided in header.
void ExtendedEuclideanAlgorithm::compute()
{
    if(h.to_ullong() == 0)
    {
        d = g;
        s = GFNumber(1);
        t = GFNumber(0);
        return;
    }

    GFNumber s2(1), s1(0), t2(0), t1(1);
    while(h.to_ullong() != 0)
    {
        GFNumber q = gf.divide(g, h);
        GFNumber r = g ^ gf.multiply(h,q);
        s = s2 ^ gf.multiply(q,s1);
        t = t2 ^ gf.multiply(q,t1);
        g = h; h = r;
        s2 = s1; s1 = s; t2 = t1; t1 = t;
        cout << gf.display(h) << endl;
    }

    d = g; s = s2; t = t2;

}

GFNumber ExtendedEuclideanAlgorithm::getD()
{
    return d;
}

GFNumber ExtendedEuclideanAlgorithm::getS()
{
    return s;
}

GFNumber ExtendedEuclideanAlgorithm::getT()
{
    return t;
}
