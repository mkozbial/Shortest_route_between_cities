#include "Mapa.h"
#include "Kolejka.h"
#include "Dijkstra.h"


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

	String a;

	for (int i = 0; i < h; i++) {

		for (int j = 0; j < w; j++) {

			if (mapa[i][j] == '*') {
				a = znajdzNazweMiasta(j, i);
			}

		}

	}
}

void Mapa::wypiszMiasta() {

	for (int i = 0; i < miasta.getRozmiar(); i++) {
		cout << miasta.miasta[i].getNazwa().getString() << endl;
	}

}

void Mapa::znajdzSasiadow() {

	for (int i = 0; i < miasta.getRozmiar(); i++) {
		bfs(w, h, miasta.miasta[i].getWspolrzedne().getX(), miasta.miasta[i].getWspolrzedne().getY(), i);
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
					miasta.pushBack(m);

					return nazwaMiasta;
				}

			}

		}

	}

}

String Mapa::nazwa(int x, int y) {

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

					return nazwaMiasta;
				}

			}

		}

	}

}

punkt Mapa::znajdzPoczatek(int x, int y) {

	punkt poczatekKoordynaty;
	char poczatek = mapa[y][x];
	int nowyX = x;
	int k = 0;

	while (true) {

		k--;
		nowyX = x + k;

		if ((mapa[y][nowyX] >= 'A' && mapa[y][nowyX] <= 'Z') && (nowyX >= 0)) {
			poczatek = mapa[y][nowyX];
		}
		else {
			break;
		}
	}

	nowyX++;
	poczatekKoordynaty.x = nowyX;
	poczatekKoordynaty.y = y;

	return poczatekKoordynaty;
}

bool Mapa::czyPrawdilowy(int x, int y) {
	return x >= 0 && x < w && y >= 0 && y < h;
}

void Mapa::bfs(int w, int h, int startX, int startY, int idx) {

	bool** odwiedzone;
	odwiedzone = new bool* [h];

	for (int i = 0; i < h; i++) {
		odwiedzone[i] = new bool[w];
	}

	for (int i = 0; i < h; i++) {

		for (int j = 0; j < w; j++) {
			odwiedzone[i][j] = false;
		}

	}

	punkt start(startX, startY);

	Kolejka kolejka;
	kolejka.enqueue(start);
	odwiedzone[start.y][start.x] = true;

	int dystans = 0;

	while (!kolejka.czyPusty()) {

		punkt p = kolejka.przedni();
		kolejka.dequeue();

		for (int dy = -1; dy <= 1; dy++) {

			for (int dx = -1; dx <= 1; dx++) {

				if (dx == 0 || dy == 0) {

					if (dx == 0 && dy == 0) continue;

					int x = p.x + dx;
					int y = p.y + dy;

					if (czyPrawdilowy(x, y) && !odwiedzone[y][x] && mapa[y][x] == '#') {

						odwiedzone[y][x] = true;
						kolejka.enqueue({ x, y, p.dystans + 1});

					} else if (czyPrawdilowy(x, y) && mapa[y][x] == '*' && !(y == startY && x == startX)) {

						p.dystans++;
						miasta.miasta[idx].sasiedzi.dodaj(nazwa(x, y), p.dystans);

					}
				}

			}
			
		}
		
	}

	for (int i = 0; i < h; i++) {
		delete[] odwiedzone[i];
	}

	delete[] odwiedzone;
}

void Mapa::wykonajPolecenia(int pytania, Wektor& miasta) {

	String** polecenia;
	polecenia = new String * [3];

	for (int i = 0; i < 3; i++) {
		polecenia[i] = new String[pytania];
	}

	String pol;
	char z;

	int i = 0, j = 0;

	while (j < pytania) {

		while (i < 3) {

			z = getchar();

			if (z == ' ') {

				polecenia[i][j] = pol;
				pol = "";
				i++;

			}
			else if (z != '\n') {

				pol.addChar(z);

			}
			else if (z == '\n' && i != 0) {

				polecenia[i][j] = pol;
				pol = "";
				i++;

			}

		}

		j++;
		i = 0;
	}

	for (int i = 0; i < 3; i++) {
		  najkrotszaDroga(polecenia[0][i], polecenia[1][i], miasta, polecenia[2][i]);
	}

	for (int i = 0; i < 3; i++) {
		delete[] polecenia[i];
	}

	delete[] polecenia;
}

int Mapa::najkrotszaDroga(String miasto, String cel, Wektor& miasta, String typ) {

	int miastIdx = miasta.znjadzIdx(miasto);
	int celIdx = miasta.znjadzIdx(cel);

	dijkstra(miasta, miastIdx, celIdx, typ);

	return 0;
}