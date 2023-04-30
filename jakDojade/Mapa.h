#pragma once
#include <iostream>
#include "punkt.h"
#include "string.h"
using namespace std;

class Mapa {
private:
	int w, h;
	char** mapa;
public:
	Mapa(int w, int h);
	void wczytajMape();
	void wypiszMape(); //do testow
	void znajdzMiasta();
	string znajdzNazweMiasta(int x, int y);
	punkt znajdzPoczatek(int x, int y);
	~Mapa();
};
