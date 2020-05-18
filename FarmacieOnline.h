#ifndef FARMACIEONLINE_H_INCLUDED
#define FARMACIEONLINE_H_INCLUDED
#include <bits/stdc++.h>
#include "Proprietar.h"
using namespace std;

class FarmacieOnline:virtual public Proprietar
{
protected:
    static int ordine;
    string adresa;
    double discount;
    int nrViz;
    static int utilizatori;
    void GenereazaAdresa();
public:
    FarmacieOnline();
    FarmacieOnline(string, double, int);
    FarmacieOnline(const FarmacieOnline&);
    FarmacieOnline & operator = (const FarmacieOnline&);
    virtual ~FarmacieOnline();
    void afisare(ostream& out) const;
    void setNrViz(int);
    void setDiscount(double );
    int getNrViz();
    double getDiscount();
    string getAdresa();
    friend istream& operator >> (istream &in, FarmacieOnline&);
    friend ostream& operator << (ostream &out,const  FarmacieOnline&);
    void Utilizatorii();
};

#endif // FARMACIEONLINE_H_INCLUDED
