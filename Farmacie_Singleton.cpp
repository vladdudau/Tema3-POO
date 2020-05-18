#include "Farmacie_Singleton.h"
#include "FarmacieFizica.h"
#include "FarmacieOnline.h"
#include "Farmacie2in1.h"
#include "exceptii.h"
#include<bits/stdc++.h>
#include<typeinfo>

using namespace std;

FarmacieSingleton* FarmacieSingleton::instance=nullptr;

FarmacieSingleton::FarmacieSingleton(string tipCab):tip(tipCab){}

FarmacieSingleton* FarmacieSingleton::getInstance(string tipCab)
{
    if(instance==nullptr)
        instance=new FarmacieSingleton(tipCab);
    return instance;
}

string FarmacieSingleton::getTip()
{
    return this->tip;
}

void FarmacieSingleton::mesaj()
{
    cout<<"Meniu:\n";
    cout<<"1.Afiseaza toate farmaciile.\n";
    cout<<"2.Arata farmaciile doar de un anumit tip.\n";
    cout<<"3.Adauga o farmacie.\n";
    cout<<"4.Farmacia cu cei mai multi angajati.\n";
    cout<<"5.Farmacia cu cel mai mare discount.\n";
    cout<<"6.Iesire\n";
}

void FarmacieSingleton::adaugaFarmacie(string tip)
{
    if(tip=="FarmacieFizica")
    {
        FarmacieFizica aux;
        cin>>aux;
        Farm.push_back(new FarmacieFizica(aux));
    }
    else if(tip=="FarmacieOnline")
    {
        FarmacieOnline aux;
        cin>>aux;
        Farm.push_back(new FarmacieOnline(aux));
    }
    else if(tip=="Farmacie2in1")
    {
        Farmacie2in1 aux;
        cin>>aux;
        Farm.push_back(new Farmacie2in1(aux));
    }
}

void FarmacieSingleton::afiseazaFarmacii()
{
    for(auto & i: Farm)
    {
        if(Farmacie2in1 *j = dynamic_cast<Farmacie2in1*>(i))
            {
                cout<<"Farmacia este 2 in 1\n";
                cout<<*j<<"\n";
            }
         else if(FarmacieFizica* j = dynamic_cast<FarmacieFizica*>(i))
            {
                cout<<"Farmacia este fizica\n";
                cout<<*j<<"\n";
            }
         else if(FarmacieOnline *j = dynamic_cast<FarmacieOnline*>(i))
            {
                cout<<"Farmacia este online\n";
                cout<<*j<<"\n";
            }

    }
}

void FarmacieSingleton::afiseazaFarmacie(string tip)
{
    for(auto & i: Farm)
    {
        if(tip=="Farmacie2in1")
        {
            if(Farmacie2in1 *j=dynamic_cast<Farmacie2in1 *>(i))
                cout<<*j<<"\n";
        }
        else if(tip=="FarmacieFizica")
        {
            if(FarmacieFizica *j=dynamic_cast<FarmacieFizica *>(i))
                cout<<*j<<"\n";
        }
        else if(tip=="FarmacieOnline")
        {
            if(FarmacieOnline *j=dynamic_cast<FarmacieOnline *>(i))
                cout<<*j<<"\n";
        }

    }
}

int FarmacieSingleton::maxAngajati()
{
    int maxi=0;
    for(auto & i: Farm)
    {
        if(Farmacie2in1 *j=dynamic_cast<Farmacie2in1 *>(i))
            if((*j).getNrAngajati()>maxi)
                maxi=(*j).getNrAngajati();
        if(FarmacieFizica *j=dynamic_cast<FarmacieFizica*>(i))
            if((*j).getNrAngajati()>maxi)
                maxi=(*j).getNrAngajati();
    }
    return maxi;
}

double FarmacieSingleton::maxDiscount()
{
    double maxi=0;
    for(auto & i: Farm)
    {
        if(Farmacie2in1 *j=dynamic_cast<Farmacie2in1 *>(i))
            if((*j).getDiscount()>maxi)
                maxi=(*j).getDiscount();
        if(FarmacieOnline *j=dynamic_cast<FarmacieOnline*>(i))
            if((*j).getDiscount()>maxi)
                maxi=(*j).getDiscount();
    }
    return maxi;
}
