#include <bits/stdc++.h>
#include "FarmacieOnline.h"
#include "exceptii.h"
using namespace std;

int FarmacieOnline::ordine=0;
int FarmacieOnline::utilizatori=0;

void FarmacieOnline::GenereazaAdresa()
{
    adresa="Dudau'sPharmachy";
    ordine++;
    string str=to_string(ordine);
    adresa+=str;
    adresa+=".ro";
}

FarmacieOnline::FarmacieOnline()
{
    GenereazaAdresa();
    discount=0;
    nrViz=0;
}

FarmacieOnline::FarmacieOnline(string adr, double disc, int viz):
    adresa(adr),discount(disc),nrViz(viz)
    {
        FarmacieOnline::utilizatori+=viz;
    }

FarmacieOnline::FarmacieOnline(const FarmacieOnline& fo)
{
    if(this!=&fo)
    {
        FarmacieOnline::utilizatori+=fo.nrViz;
        this->nrViz=fo.nrViz;
        this->discount=fo.discount;
        this->adresa=fo.adresa;
    }
}

FarmacieOnline &FarmacieOnline::operator = (const FarmacieOnline &fo)
{
    if(this!=&fo)
    {
        FarmacieOnline::utilizatori+=fo.nrViz;
        this->nrViz=fo.nrViz;
        this->discount=fo.discount;
        this->adresa=fo.adresa;
    }
    return *this;
}

FarmacieOnline::~FarmacieOnline()
{
    utilizatori-=nrViz;
    nrViz=0;
    adresa="";
    discount=0;
}

void FarmacieOnline::afisare(ostream& out) const
{
    FarmacieOnline fo=*this;
    out<<dynamic_cast<Proprietar&>(fo);
    out<<"Adresa web a farmaciei este: "<<adresa<<".\n";
    out<<"Farmacia are un numar de: "<<nrViz<<" vizitatori.\n";
    out<<"Discount-ul utilizat este de: "<<discount<<" procente.\n";
}

ostream & operator<<(ostream &out, const FarmacieOnline &fo)
{
    fo.afisare(out);
    return out;
}
istream & operator >> (istream &in, FarmacieOnline &fo)
{
    cout<<"Introduceti adresa web: ";
    in>>fo.adresa;
    cout<<"Introduceti numarul de utilizatori: ";
    in>>fo.nrViz;
    if(fo.nrViz<0)
        throw Exception("Numarul de vizitatori trebuie sa fie pozitiv");
    cout<<"Dati discount-ul site-ului: ";
    in>>fo.discount;
    FarmacieOnline::utilizatori+=fo.nrViz;
    return in;
}

void FarmacieOnline::setNrViz(int nr)
{
    if(nr<0)
        throw Exception("Nr de vizitatori trebuie sa fie pozitiv");
    FarmacieOnline::utilizatori-=nrViz;
    FarmacieOnline::utilizatori+=nr;
    nrViz=nr;
}

void FarmacieOnline::Utilizatorii()
{
    cout<<FarmacieOnline::utilizatori<<"\n";
}

void FarmacieOnline::setDiscount(double dis)
{
    discount=dis;
}

int FarmacieOnline::getNrViz()
{
    return nrViz;
}

string FarmacieOnline::getAdresa()
{
    return adresa;
}

double FarmacieOnline::getDiscount()
{
    return discount;
}


