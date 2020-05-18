#include <bits/stdc++.h>
#include "Farmacie.h"
#include "FarmacieFizica.h"
#include "FarmacieOnline.h"
#include "Farmacie2in1.h"
#include "GestionareFarmacii.h"
#include "exceptii.h"

using namespace std;

template <class T>
GestionareFarmacii<T>::GestionareFarmacii():id(0)
{
    nrOrd=0;
    nrFarm=0;
    farmacii=NULL;
}

template <class T>
GestionareFarmacii<T>::GestionareFarmacii(int NRORD, int ID, int NRFARM, Farmacie<T> *Farmacii):id(ID)
{
    nrOrd=NRORD;
    nrFarm=NRFARM;
    farmacii=new Farmacie<T>[nrFarm];
    for(int i=0;i<nrFarm;i++)
        this->farmacii=Farmacii[i];
}

template <class T>
GestionareFarmacii<T>::~GestionareFarmacii()
{
    delete[] farmacii;
}

template <class T>
GestionareFarmacii<T>::GestionareFarmacii(const GestionareFarmacii<T> &gf)
{
    if(this!=&gf)
    {
        if(this->nrFarm)
            delete[] this->farmacii;
        this->nrOrd=gf.nrOrd;
        this->nrFarm=gf.nrFarm;
        this->farmacii=new Farmacie<T> [this->nrFarm];
        for(int i=0;i<nrFarm;++i)
            this->farmacii[i]=gf.farmacii[i];
    }
}

template <class T>
GestionareFarmacii<T> &GestionareFarmacii<T>::operator=(const GestionareFarmacii<T> &gf)
{
    if(this!=&gf)
    {
        if(this->nrFarm)
            delete[] this->farmacii;
        this->nrOrd=gf.nrOrd;
        this->nrFarm=gf.nrFarm;
        this->farmacii=new Farmacie<T> [this->nrFarm];
        for(int i=0;i<nrFarm;++i)
            this->farmacii[i]=gf.farmacii[i];
    }
    return *this;
}

template <class T>
void operator +=(GestionareFarmacii<T> &gf, T farmacie)
{
    Farmacie<T> farm[gf.nrFarm];
    for(int i=0;i<gf.nrFarm;++i)
        farm[i]=gf.farmacii[i];
    if(gf.nrFarm)
        delete [] gf.farmacii;
    gf.nrFarm++;
    gf.nrOrd++;
    gf.farmacii=new Farmacie<T> [gf.nrFarm];
    for(int i=0;i<gf.nrFarm-1;++i)
        gf.farmacii[i]=farm[i];
    Farmacie<T> FarmAdaug(farmacie);
    gf.farmacii[gf.nrFarm-1]=FarmAdaug;
}

template <class T>
istream & operator >> (istream &in, GestionareFarmacii<T> &gf)
{
    if(gf.nrFarm)
        delete[] gf.farmacii;
    cout<<"Cititi numarul de farmacii: ";
    in>>gf.nrFarm;
    if(gf.nrFarm<0)
        throw Exception("Numarul de farmacii trebuie sa fie mai mare egal decat 0");
    gf.farmacii=new Farmacie<T>[gf.nrFarm];
    for(int i=0;i<gf.nrFarm;++i)
        {
           cin>>gf.farmacii[i];
        }
    return in;
}

template <class T>
ostream & operator << (ostream &out, const GestionareFarmacii<T> &gf)
{
    out<<"Id-ul lantului este "<<gf.id<<"\n";
    if(gf.nrFarm!=0)
    {
        out<<"Farmaciile din lant sunt: \n";
        for(int i=0;i<gf.nrFarm;++i)
            out<<gf.farmacii[i]<<"\n";

    }
    return out;
}





