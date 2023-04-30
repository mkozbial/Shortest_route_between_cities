#pragma once
#include <iostream>
#include "Wektor.h"

using namespace std;

class Mapa {
private:
	int w, h;

public:
	char** mapa;
	Wektor miasta;
	Mapa(int w, int h);
	void wczytajMape();
	void wypiszMape(); //do testow
	void znajdzMiasta();
	void wypiszMiasta();
	int getW() const;
	int getH() const;
	String znajdzNazweMiasta(int x, int y);
	punkt znajdzPoczatek(int x, int y);
	~Mapa();
};
