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

				if (mapa[y + i][x + j] != '#' && mapa[y + i][x + j] != '.' && mapa[y + i][x + j] != '*') {

					poczatek = znajdzPoczatek(x + j, y + i);
					String nazwaMiasta;
					newX = poczatek.x;
					koniec = mapa[poczatek.y][newX];
					nazwaMiasta.addChar(koniec);
					k = 0;

					while ((newX >= 0 && newX < w) && (mapa[y + i][newX] != '#' && mapa[y + i][newX] != '.' && mapa[y + i][newX] != '*')) {
						k++;
						newX = poczatek.x + k;
						koniec = mapa[poczatek.y][newX];
						if ((newX >= 0 && newX < w) && (mapa[y + i][newX] != '#' && mapa[y + i][newX] != '.' && mapa[y + i][newX] != '*')) {
							nazwaMiasta.addChar(koniec);
						}
						else {
							break;
						}
							
					}

					/*while (true) {

						nazwaMiasta.addChar(koniec);
						k++;
						newX = poczatek.x + k;

						if ((newX >= 0) && (mapa[y + i][x + j] != '#' && mapa[y + i][x + j] != '.' && mapa[y + i][x + j] != '*')) {
							koniec = mapa[poczatek.y][newX];
						}
						else {
							break;
						}
					}*/

					Miasto m(nazwaMiasta, wspolrzedne);
					miasta.pushBack(m);

					return nazwaMiasta;
				}

			}

		}

	}
	return "";
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

				if (mapa[y + i][x + j] != '#' && mapa[y + i][x + j] != '.' && mapa[y + i][x + j] != '*') {

					poczatek = znajdzPoczatek(x + j, y + i);
					String nazwaMiasta;
					newX = poczatek.x;
					koniec = mapa[poczatek.y][newX];
					nazwaMiasta.addChar(koniec);
					k = 0;

					while ((newX >= 0 && newX < w) && (mapa[y + i][newX] != '#' && mapa[y + i][newX] != '.' && mapa[y + i][newX] != '*')) {
						k++;
						newX = poczatek.x + k;
						koniec = mapa[poczatek.y][newX];
						if ((newX >= 0 && newX < w) && (mapa[y + i][newX] != '#' && mapa[y + i][newX] != '.' && mapa[y + i][newX] != '*')) {
							nazwaMiasta.addChar(koniec);
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
	return "";
}

punkt Mapa::znajdzPoczatek(int x, int y) {

	punkt poczatekKoordynaty;
	char poczatek = mapa[y][x];
	int nowyX = x;
	int k = 0;

	while (true) {

		k--;
		nowyX = x + k;

		if ((nowyX >= 0) && (mapa[y][nowyX] != '#' && mapa[y][nowyX] != '.' && mapa[y][nowyX] != '*')) {
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
	String buffer, buffer2;
	char z;
	int typ;
	getchar();
	for (int i = 0; i < pytania; i++) {
		z = getchar();
		while (z != ' ') {
			buffer.addChar(z);
			z = getchar();
		}
		z = getchar();
		while (z != ' ') {
			buffer2.addChar(z);
			z = getchar();
		}

		cin >> typ;
		z = getchar();
		
		najkrotszaDroga(buffer, buffer2, miasta, typ);
		
		buffer = "";
		buffer2 = "";
		
	}
}

int Mapa::najkrotszaDroga(String miasto, String cel, Wektor& miasta, int typ) {

	int miastIdx = miasta.znajdzIdx(miasto);
	int celIdx = miasta.znajdzIdx(cel);
	dijkstra(miasta, miastIdx, celIdx, typ);

	return 0;
}

void Mapa::dodajLoty(int liczbaLotnisk) {
	String buffer, buffer2;
	char z;
	int czas;
	getchar();
	for (int i = 0; i < liczbaLotnisk; i++) {
		z = getchar();
		while (z != ' ') {
			buffer.addChar(z);
			z = getchar();	
		}
		z = getchar();
		while (z != ' ') {
			buffer2.addChar(z);
			z = getchar();
		}

		cin >> czas;
		z = getchar();
		int miastIdx = miasta.znajdzIdx(buffer);
		miasta.miasta[miastIdx].sasiedzi.dodaj(buffer2, czas);
		buffer = "";
		buffer2 = "";
	}
	/*String** lotniska;
	lotniska = new String * [liczbaLotnisk];

	for (int i = 0; i < liczbaLotnisk; i++) {
		lotniska[i] = new String[3];
	}

	String lot;
	char z;

	int i = 0, j = 0;

	while (j < liczbaLotnisk) {

		while (i < 3) {

			z = getchar();

			if (z == ' ') {

				lotniska[j][i] = lot;
				lot = "";
				i++;

			}
			else if (z != '\n') {

				lot.addChar(z);

			}
			else if (z == '\n' && i != 0) {

				lotniska[j][i] = lot;
				lot = "";
				i++;

			}

		}

		j++;
		i = 0;
	}

	for (int i = 0; i < liczbaLotnisk; i++) {
		int miastIdx = miasta.znjadzIdx(lotniska[i][0]);
		int celIdx = miasta.znjadzIdx(lotniska[i][1]);

		miasta.miasta[miastIdx].sasiedzi.dodaj(lotniska[i][1], lotniska[i][2].stringToInt(lotniska[i][2].getString()));
	}

	for (int i = 0; i < liczbaLotnisk; i++) {
		delete[] lotniska[i];
	}

	delete[] lotniska;*/

	

}