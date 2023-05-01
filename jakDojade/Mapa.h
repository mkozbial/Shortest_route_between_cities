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
	void znajdzSasiadow();
	int getW() const;
	int getH() const;
	String znajdzNazweMiasta(int x, int y);
	punkt znajdzPoczatek(int x, int y);
	bool is_valid(int x, int y);
	bool is_star(int x, int y);
	void bfs(int w, int h, int startX, int startY, int idx);
	String nazwa(int x, int y);
	~Mapa();
};
