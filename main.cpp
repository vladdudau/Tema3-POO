#include "Proprietar.h"
#include "FarmacieFizica.h"
#include "FarmacieOnline.h"
#include "Farmacie2in1.h"
#include "GestionareFarmacii.h"
#include "GestionareFarmacii.cpp"
#include "Farmacie_Singleton.h"
#include "exceptii.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    try
    {
    unique_ptr<FarmacieSingleton> F (FarmacieSingleton::getInstance("tip"));
    while(true)
    {
        F->mesaj();
        int alegere;
        cout<<"\n";
        cout<<"Alege una din optiuni:";
        cout<<"\n";
        cin>>alegere;
        if(alegere<=0)
            throw Exception("Alegerea trebuie sa fie mai mare decat 0");
        if(alegere==1)
        {
            F->afiseazaFarmacii();
            cout<<"\n";
            cout<<"\n";
        }
        else if(alegere==2)
        {
            string tip;
            cout<<"Dati tipul farmaciei:";
            cin>>tip;
            if(tip!="FarmacieOnline" and tip!="Farmacie2in1" and tip!="FarmacieFizica")
                throw Exception("Tipul introdus este gresit");
            F->afiseazaFarmacie(tip);
            cout<<"\n";
            cout<<"\n";
        }
        else if(alegere==3)
        {
            string tip;
            cout<<"Dati tipul farmaciei:";
            cin>>tip;
            if(tip!="FarmacieOnline" and tip!="Farmacie2in1" and tip!="FarmacieFizica")
        {
            throw Exception("Tipul introdus este gresit");
        }
            F->adaugaFarmacie(tip);
            cout<<"\n";
            cout<<"\n";
        }
        else if(alegere==4)
        {
            cout<<"Farmacia cu numar maxim de angajati este: ";
            cout<<F->maxAngajati();
            cout<<"\n";
            cout<<"\n";
        }
        else if(alegere==5)
        {
            cout<<"Farmacia cu cel mai mare discount este: ";
            cout<<F->maxDiscount();
            cout<<"\n\n";
        }
        else if(alegere==6)
        {
            cout<<"Ati ales sa iesiti din meniu.";
            break;
        }
        else
        {
            cout<<"Ati introdus o tasta incorecta!";
        }
    }
    }
    catch(Exception &exception)
    {
        cout << "A aparut o exceptie : (" << exception.what() << ")\n";
    }
    catch(exception &exception)
    {
        cout << "Alta exceptie din clasa std::exception a aparut (" << exception.what() << ")\n";
    }
    return 0;
}
