#include <bits/stdc++.h>
#include "FarmacieFizica.h"
#include "exceptii.h"
using namespace std;
int FarmacieFizica::nrOrdine=0;
void FarmacieFizica::GenereazaNume()
{
    nrOrdine++;
    string ordine=to_string(nrOrdine);
    denumire="Dudau's Pharmachy"+ordine;
}

FarmacieFizica::FarmacieFizica()
{
    GenereazaNume();
    nrAngajati=0;
    profituri=NULL;
    nrLuni=0;
}

FarmacieFizica::FarmacieFizica(string den, int ang, int nrl, double *prof):
    denumire(den),nrAngajati(ang),nrLuni(nrl)
{
    nrOrdine++;
    this->profituri=new double[nrl];
    for(int i=0;i<nrl;++i)
    {
        this->profituri[i]=prof[i];
    }
}
FarmacieFizica::FarmacieFizica(const FarmacieFizica &f)
{
        this->denumire=f.denumire;
        this->nrLuni=f.nrLuni;
        this->nrAngajati=f.nrAngajati;
        this->profituri=new double[this->nrLuni];
        for(int i=0;i<this->nrLuni;++i)
            this->profituri[i]=f.profituri[i];

}

FarmacieFizica &FarmacieFizica::operator = (const FarmacieFizica& f)
{
    if(this!=&f)
    {
        if(this->nrLuni)
            delete[] this->profituri;
        this->denumire=f.denumire;
        this->nrLuni=f.nrLuni;
        this->nrAngajati=nrAngajati;
        this->profituri=new double[this->nrLuni];
        for(int i=0;i<this->nrLuni;++i)
            this->profituri[i]=f.profituri[i];
    }
    return *this;
}

FarmacieFizica::~FarmacieFizica()
{
    if(this->nrLuni)
    {
        delete[] this->profituri;
    }
    this->nrLuni=0;
    this->nrAngajati=0;
    this->denumire="";
}

void FarmacieFizica::adaugaProfit(double profit)
{
    if(profit<=0)
        throw Exception("Profitul trebuie sa fie pozitiv mai mare decat 0");
    double p[nrLuni];
    for(int i=0;i<nrLuni;++i)
    {
        p[i]=profituri[i];
    }
    delete[] profituri;
    profituri=new double[nrLuni+1];
    for(int i=0;i<nrLuni;i++)
        profituri[i]=p[i];
    profituri[nrLuni]=profit;
    nrLuni++;
}

void FarmacieFizica::arataActivitate() const
{
    if(nrLuni==0)
    {
        cout<<"Abia am inceput luna aceasta, deci nu avem activitate!\n";
    }
    else
    {
        for(int i=0;i<nrLuni;++i)
            cout<<"Profitul pe luna "<<i+1<< " este: "<<profituri[i]<<".\n";
    }
    cout<<"\n";
}

int FarmacieFizica::getNrAngajati() const
{
    return nrAngajati;
}

int FarmacieFizica::getNrLuni()  const
{
    return nrLuni;
}

string FarmacieFizica::getDenumire()  const
{
    return denumire;
}

int FarmacieFizica::getNrOrdine() const
{
    return nrOrdine;
}

istream & operator >> (istream &in, FarmacieFizica &f)
{
    if(f.nrLuni!=0)
        delete[] f.profituri;
    f.profituri=NULL;
    cout<<"Dati denumirea farmaciei fizice: ";
    in>>f.denumire;
    cout<<"Dati numarul de angajati: ";
    in>>f.nrAngajati;
    if(f.nrAngajati<0)
        throw Exception("Numarul de angajati trebuie sa fie pozitiv");
    cout<<"Dati numarul de luni de cand exista farmacia: ";
    in>>f.nrLuni;
    if(f.nrLuni<0)
        throw Exception("Numarul de luni trebuie sa fie pozitiv");
    if(f.nrLuni!=0)
    {
        f.profituri=new double[f.nrLuni];
        cout<<"Cititi profiturile pentru fiecare luna: ";
        for(int i=0;i<f.nrLuni;++i)
            in>>f.profituri[i];
    }
    return in;
}

void FarmacieFizica::afisare(ostream& out) const
{
    FarmacieFizica f=*this;
    out<<dynamic_cast<Proprietar&>(f);
    out<<"Numarul de ordine al farmaciei este: "<<nrOrdine<<".\n";
    out<<"Numele farmaciei este : "<< denumire <<" si are "<< nrAngajati << " angajati.\n";
    if(nrLuni==0)
        out<<"Nu avem inca activitate"<<"\n";
    else
    {
        out<<"Va vom arata activitatea pe "<< nrLuni <<" luni.\n";
        bool virgula=true;
        for(int i=0;i<nrLuni;++i)
            if(virgula)
        {
            out<<profituri[i];
            virgula=false;
        }
            else
        {
            out<<", ";
            out<<profituri[i];
        }
        out<<".";
    }
    out<<"\n";
}
ostream & operator << (ostream &out, const FarmacieFizica &f)
{
    f.afisare(out);
    return out;
}
