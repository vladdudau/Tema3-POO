#include <bits/stdc++.h>
#include "FarmacieFizica.h"
#include "FarmacieOnline.h"
#include "Farmacie2in1.h"
#include "exceptii.h"
using namespace std;

Farmacie2in1::Farmacie2in1():FarmacieFizica(),FarmacieOnline(){}

Farmacie2in1::Farmacie2in1(string den, int ang, int nrl, double *prof, string adr, double disc, int viz):
    FarmacieFizica(den,ang,nrl,prof),FarmacieOnline(adr,disc,viz){}

Farmacie2in1::Farmacie2in1(const Farmacie2in1 &f21):FarmacieFizica(f21),FarmacieOnline(f21){}

Farmacie2in1::~Farmacie2in1(){}

Farmacie2in1 &Farmacie2in1::operator = (const Farmacie2in1 &f21)
{
    if(this!=&f21)
    {
        FarmacieFizica::operator=(f21);
        FarmacieOnline::operator=(f21);
    }
    return *this;
}

void Farmacie2in1::afisare(ostream &out) const
{
    FarmacieFizica::afisare(out);
    out<<"Adresa web a farmaciei este: "<<adresa<<".\n";
    out<<"Farmacia are un numar de: "<<nrViz<<" vizitatori.\n";
    out<<"Discount-ul utilizat este de: "<<discount<<" procente.\n";
}

istream & operator >> (istream& in, Farmacie2in1 &f21)
{
    in>>dynamic_cast<FarmacieFizica&>(f21);
    in>>dynamic_cast<FarmacieOnline&>(f21);
    return in;
}

ostream & operator << (ostream& out, const Farmacie2in1 &f21)
{
    f21.afisare(out);
    return out;
}
