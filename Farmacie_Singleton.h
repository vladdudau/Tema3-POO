#ifndef FARMACIE_SINGLETON_H_INCLUDED
#define FARMACIE_SINGLETON_H_INCLUDED
#pragma once
#include<string>
#include<vector>
#include "Proprietar.h"
using namespace std;

class FarmacieSingleton
{
private:
	string tip;
	static FarmacieSingleton* instance;
	FarmacieSingleton(string=" ");
	vector<Proprietar*> Farm;

public:
	static FarmacieSingleton* getInstance(string);
	string getTip();
	void adaugaFarmacie(string);
	void afiseazaFarmacii();
	void afiseazaFarmacie(string);
    void mesaj();
    int maxAngajati();
    double maxDiscount();
};

#endif // FARMACIE_SINGLETON_H_INCLUDED
