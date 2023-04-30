#include "Mapa.h"
#include "Bfs.h"

Mapa::Mapa(int w, int h) {
	this->w = w;
	this->h = h;
	mapa = new char*[h];
	for (int i = 0; i < h; i++) {
		mapa[i] = new char[w];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			mapa[i][j] = NULL;
		}
	}
}

Mapa::~Mapa() {
	for (int i = 0; i < h; i++) {
		delete[] mapa[i];
	}
	delete[] mapa;
}

void Mapa::wczytajMape() {
	char z;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			z = getchar();
			if(z != '\n')
				mapa[i][j] = z;
			else {
				j--;
			}
		}
	}
}

void Mapa::wypiszMape() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << mapa[i][j];
		}
		cout << endl;
	}
}

void Mapa::znajdzMiasta() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (mapa[i][j] == '*') {
				znajdzNazweMiasta(j, i);
			}
		}
	}
}

void Mapa::wypiszMiasta() {
	for (int i = 0; i < miasta.getSize(); i++) {
		cout << miasta[i].getNazwa().getString() << endl;
	}
}

int Mapa::getW() const {
	return w;
}

int Mapa::getH() const {
	return h;
}

String Mapa::znajdzNazweMiasta(int x, int y) {
	punkt poczatek;
	punkt wspolrzedne(x, y);
	char koniec;
	int newX;
	int k;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x + j >= 0 && x + j < w && y + i >= 0 && y + i < h) {
				if (mapa[y + i][x + j] >= 'A' && mapa[y + i][x + j] <= 'Z') {
					poczatek = znajdzPoczatek(x + j, y + i);
					String nazwaMiasta;
					newX = poczatek.x;
					koniec = mapa[poczatek.y][newX];
					k = 0;
					while (true) {
						nazwaMiasta.addChar(koniec);
						k++;
						newX = poczatek.x + k;
						if ((mapa[poczatek.y][newX] >= 'A' && mapa[poczatek.y][newX] <= 'Z') && (newX >= 0)) {
							koniec = mapa[poczatek.y][newX];
						}
						else {
							break;
						}
					}
					Miasto m(nazwaMiasta, wspolrzedne);
					miasta.push_back(m);
					return nazwaMiasta;
				}
			}
		}
	}
}

punkt Mapa::znajdzPoczatek(int x, int y) {
punkt poczatekKoordynaty;
	char poczatek = mapa[y][x];
	int newX = x;
	int k = 0;
	while (true) {
		k--;
		newX = x + k;
		if ((mapa[y][newX] >= 'A' && mapa[y][newX] <= 'Z') && (newX >= 0)) {
			poczatek = mapa[y][newX];
		}
		else {
			break;
		}
	}
	newX++;
	poczatekKoordynaty.x = newX;
	poczatekKoordynaty.y = y;

	return poczatekKoordynaty;
}