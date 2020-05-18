#include <bits/stdc++.h>
#include "Proprietar.h"
#include "exceptii.h"
using namespace std;
string Proprietar::nume;
Proprietar::Proprietar()
{
    if(nume.size()==0)
        cin>>*this;
}

Proprietar::~Proprietar(){}

void Proprietar::setNume(string cNume)
{
    Proprietar::nume=cNume;
}

string Proprietar::getNume() const
{
    return nume;
}

istream & operator >> (istream &in, Proprietar &p)
{
    cout<<"Dati numele proprietarului: ";
    string name;
    in>>name;
    Proprietar::nume=name;
    return in;
}
ostream & operator << (ostream &out, const Proprietar &p)
{
    out<<"Numele proprietarului este: "<< Proprietar::nume<<".\n";
    return out;
}
