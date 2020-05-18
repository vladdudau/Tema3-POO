#ifndef FARMACIEFIZICA_H_INCLUDED
#define FARMACIEFIZICA_H_INCLUDED
#include <bits/stdc++.h>
#include "Proprietar.h"
using namespace std;

class FarmacieFizica:virtual public Proprietar
{
protected:
    string denumire;
    static int nrOrdine;
    int nrAngajati;
    int nrLuni;
    double *profituri;
    void GenereazaNume();
public:
    FarmacieFizica();
    FarmacieFizica(string, int , int, double* );
    FarmacieFizica(const FarmacieFizica&);
    FarmacieFizica & operator = (const FarmacieFizica&);
    virtual ~FarmacieFizica();
    void afisare(ostream &out) const;
    friend istream& operator >> (istream &in, FarmacieFizica&);
    friend ostream& operator << (ostream &out, const FarmacieFizica&);
    string getDenumire() const;
    int getNrAngajati() const;
    int getNrLuni() const;
    void adaugaProfit(double);
    void arataActivitate() const;
    int getNrOrdine() const;
};

#endif // FARMACIEFIZICA_H_INCLUDED
