#ifndef FARMACIE2IN1_H_INCLUDED
#define FARMACIE2IN1_H_INCLUDED
#include<bits/stdc++.h>
#include "Proprietar.h"
#include "FarmacieFizica.h"
#include "FarmacieOnline.h"

class Farmacie2in1:public FarmacieFizica, public FarmacieOnline
{
public:
    Farmacie2in1();
    Farmacie2in1(string, int, int, double*, string, double, int);
    Farmacie2in1(const Farmacie2in1&);
    virtual ~Farmacie2in1();
    Farmacie2in1 &operator = (const Farmacie2in1&);
    friend istream& operator >> (istream &in, Farmacie2in1& );
    friend ostream& operator << (ostream &out, const Farmacie2in1& );
    void afisare(ostream& out) const;
};
#endif // FARMACIE2IN1_H_INCLUDED
