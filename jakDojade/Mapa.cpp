#include "Mapa.h"

Mapa::Mapa(int w, int h) {
	this->w = w;
	this->h = h;
	mapa = new char*[h];
	for (int i = 0; i < h; i++) {
		mapa[i] = new char[w];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			mapa[j][i] = NULL;
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
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> mapa[i][j];
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
				cout << znajdzNazweMiasta(j, i) << endl;
			}
		}
	}
}

string Mapa::znajdzNazweMiasta(int x, int y) {
	punkt poczatek;
	char koniec;
	int newX;
	int k;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x + j >= 0 && x + j < h && y + i >= 0 && y + i < w) {
				if (mapa[y + i][x + j] >= 'A' && mapa[y + i][x + j] <= 'Z') {
					poczatek = znajdzPoczatek(x + j, y + i);
					string nazwaMiasta;
					newX = poczatek.x;
					koniec = mapa[poczatek.y][newX];
					k = 0;
					while (true) {
						nazwaMiasta += koniec;
						k++;
						newX = poczatek.x + k;
						if ((mapa[poczatek.y][newX] >= 'A' && mapa[poczatek.y][newX] <= 'Z') && (newX >= 0)) {
							koniec = mapa[poczatek.y][newX];
						}
						else {
							break;
						}
					}
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
	/*int i = 0;*/
	int k = 0;
	/*(poczatek >= 'A' && poczatek <= 'Z') && (newX >= 0)*/
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

	/*do {
		newX = x - i;
		poczatek = mapa[y][newX];
		i--;
	}while((poczatek >= 'A' && poczatek <= 'Z') && (newX > 0 && newX < w));*/
	newX++;
	poczatekKoordynaty.x = newX;
	poczatekKoordynaty.y = y;

	return poczatekKoordynaty;
}