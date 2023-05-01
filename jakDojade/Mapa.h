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
	void wypiszMiasta();

	void znajdzMiasta();
	void znajdzSasiadow();
	String znajdzNazweMiasta(int x, int y);
	String nazwa(int x, int y);
	punkt znajdzPoczatek(int x, int y);

	int getW() const;
	int getH() const;

	bool czyPrawdilowy(int x, int y);

	void bfs(int w, int h, int startX, int startY, int idx);

	void wykonajPolecenia(int pytania, Wektor& miasta);
	int najkrotszaDroga(String miasto, String cel, Wektor& miasta, String typ);

	~Mapa();
};
