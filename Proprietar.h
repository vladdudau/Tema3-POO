#ifndef PROPRIETAR_H_INCLUDED
#define PROPRIETAR_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class Proprietar
{
protected:
    static string nume;
public:
    Proprietar();
    virtual ~Proprietar();
    virtual void afisare(ostream& out) const=0;
    friend istream& operator >> (istream & in, Proprietar& p);
    friend ostream& operator << (ostream &out, const Proprietar& p);
    string getNume() const;
    static void setNume(string cNume);
};

#endif // PROPRIETAR_H_INCLUDED
