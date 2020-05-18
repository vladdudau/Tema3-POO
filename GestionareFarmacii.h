#ifndef GESTIONAREFARMACII_H_INCLUDED
#define GESTIONAREFARMACII_H_INCLUDED
#include "Farmacie.h"
#include "FarmacieOnline.h"
#include "Farmacie.cpp"
#include <bits/stdc++.h>
#pragma once
using namespace std;

template<class T> class GestionareFarmacii;
template<class T> istream & operator >> (istream &in, GestionareFarmacii<T> &gf);
template<class T> ostream & operator << (ostream &out, const GestionareFarmacii<T> &gf);
template<class T> void operator += (GestionareFarmacii<T> &gf, T f);

template <class T>
class GestionareFarmacii
{
private:
    int nrOrd;
    const int id;
    int nrFarm;
    Farmacie<T> *farmacii;
public:
    GestionareFarmacii();
    GestionareFarmacii(int, int, int, Farmacie<T> *f);
    ~GestionareFarmacii();
    GestionareFarmacii(const GestionareFarmacii<T> &);
    GestionareFarmacii<T> &operator = (const GestionareFarmacii<T> &);
    friend void operator += < > (GestionareFarmacii<T> &gf, T f);
    friend istream& operator >> <>(istream &in, GestionareFarmacii<T> &f);
    friend ostream& operator << <>(ostream &out, const GestionareFarmacii<T> &f);
    int getId();
    int getnrFarm();
};

template<>
class GestionareFarmacii<FarmacieOnline>
{
private:
    int nrFarma;
    FarmacieOnline *farmacii;
public:
    GestionareFarmacii()
    {
        nrFarma=0;
        farmacii=NULL;
    }
    GestionareFarmacii(int nrF, FarmacieOnline *f)
    {
        nrFarma=nrF;
        farmacii=new FarmacieOnline[this->nrFarma];
        for(int i=0;i<nrFarma;i++)
            this->farmacii[i]=f[i];
    }
    ~GestionareFarmacii()
    {
        delete[] farmacii;
    }
    GestionareFarmacii(const GestionareFarmacii<FarmacieOnline> &f)
    {
        if(this!=&f)
    {
        if(this->nrFarma)
            delete[] this->farmacii;
        this->nrFarma=f.nrFarma;
        this->farmacii=new FarmacieOnline [this->nrFarma];
        for(int i=0;i<nrFarma;++i)
            this->farmacii[i]=f.farmacii[i];
    }
    }
    GestionareFarmacii<FarmacieOnline> &operator = (const GestionareFarmacii<FarmacieOnline> &f)
    {
        if(this!=&f)
    {
        if(this->nrFarma)
            delete[] this->farmacii;
        this->nrFarma=f.nrFarma;
        this->farmacii=new FarmacieOnline [this->nrFarma];
        for(int i=0;i<nrFarma;++i)
            this->farmacii[i]=f.farmacii[i];
    }
        return *this;
    }
    friend void operator +=  (GestionareFarmacii<FarmacieOnline> &gf, FarmacieOnline farmacie)
    {
        FarmacieOnline farm[gf.nrFarma];
        for(int i=0;i<gf.nrFarma;++i)
            farm[i]=gf.farmacii[i];
        if(gf.nrFarma)
            delete [] gf.farmacii;
        gf.nrFarma++;
        gf.farmacii=new FarmacieOnline [gf.nrFarma];
        for(int i=0;i<gf.nrFarma-1;++i)
            gf.farmacii[i]=farm[i];
        FarmacieOnline FarmAdaug(farmacie);
        gf.farmacii[gf.nrFarma-1]=FarmAdaug;
    }
    friend istream& operator >> (istream &in, GestionareFarmacii<FarmacieOnline> &gf)
    {
        if(gf.nrFarma)
            delete[] gf.farmacii;
        cout<<"Cititi numarul de farmacii: ";
        in>>gf.nrFarma;
        if(gf.nrFarma<0)
            throw Exception("Numarul de farmacii trebuie sa fie mai mare egal decat 0");
        gf.farmacii=new FarmacieOnline[gf.nrFarma];
        for(int i=0;i<gf.nrFarma;++i)
        {
           cin>>gf.farmacii[i];
        }
    return in;
    }
    friend ostream& operator << (ostream &out, const GestionareFarmacii<FarmacieOnline> &f)
    {
       if(f.nrFarma!=0)
    {
        out<<"Specializare pentru Farmacia Online, afisam numarul de vizitatori pentru fiecare farmacie:";
        for(int i=0;i<f.nrFarma;++i)
            out<<f.farmacii[i].getNrViz()<<"\n";

    }
    return out;
    }
};
#endif // GESTIONAREFARMACII_H_INCLUDED
