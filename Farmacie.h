#ifndef FARMACIE_H_INCLUDED
#define FARMACIE_H_INCLUDED
#include <bits/stdc++.h>
#include "FarmacieFizica.h"
#include "FarmacieOnline.h"
using namespace std;

template<class T> class Farmacie;
template<class T> istream & operator >> (istream &in, Farmacie<T> &f);
template<class T> ostream & operator << (ostream &out,const Farmacie<T> &f);

template<class T>
class Farmacie
{
private:
    T farmacie;
public:
    Farmacie();
    Farmacie(T f);
    Farmacie(const Farmacie<T> &);
    ~Farmacie();
    Farmacie<T> &operator = (const Farmacie<T> &);
    friend ostream & operator << <>(ostream & out, const Farmacie<T> & );
    friend istream & operator >> <> (istream & in, Farmacie<T> & );
};



#endif // FARMACIE_H_INCLUDED
