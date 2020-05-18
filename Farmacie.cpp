#include <bits/stdc++.h>
#include "Farmacie.h"
#include "exceptii.h"
using namespace std;

template <class T>
Farmacie<T>::Farmacie(){}

template <class T>
Farmacie<T>::Farmacie(T f)
{
    farmacie=f;
}

template <class T>
Farmacie<T>::Farmacie(const Farmacie<T> &f)
{
    if(this!=&f)
    {
        this->farmacie=f;
    }
}

template <class T>
Farmacie<T> & Farmacie<T>::operator=(const Farmacie<T> &f) {
    if (this != &f){
        this->farmacie = f.farmacie;
    }
    return *this;
}

template <class T>
Farmacie<T>::~Farmacie(){}

template <class T>
istream & operator>> (istream &in , Farmacie<T> &f){
    in >> f.farmacie;
    return in;
}

template <class T>
ostream & operator << (ostream & out, const Farmacie<T> &f){
    out << f.farmacie;
    return out;
}
