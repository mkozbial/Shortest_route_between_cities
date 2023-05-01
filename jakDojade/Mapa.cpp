#include "Mapa.h"
#include "Kolejka.h"

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
	for (int i = 0; i < miasta.getSize(); i++) {
		cout << miasta.miasta[i].getNazwa().getString() << endl;
	}

}

void Mapa::znajdzSasiadow() {
	for (int i = 0; i < miasta.getSize(); i++) {
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
					miasta.push_back(m);
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

bool Mapa::is_valid(int x, int y) {
	return x >= 0 && x < w && y >= 0 && y < h;
}

bool Mapa::is_star(int x, int y) {
	return mapa[y][x] == '*';
}

void Mapa::bfs(int w, int h, int startX, int startY, int idx) {
	bool** visited;
	visited = new bool* [h];
	for (int i = 0; i < h; i++) {
		visited[i] = new bool[w];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visited[i][j] = false;
		}
	}

	punkt start(startX, startY);

	Kolejka kolejka;
	kolejka.enqueue(start);
	visited[start.y][start.x] = true;
	int dystans = 0;
	while (!kolejka.isEmpty()) {
		punkt p = kolejka.front();
		kolejka.dequeue();

		for (int dy = -1; dy <= 1; dy++) {
			for (int dx = -1; dx <= 1; dx++) {
				if (dx == 0 || dy == 0) {
					if (dx == 0 && dy == 0) continue;
					int x = p.x + dx;
					int y = p.y + dy;
					if (is_valid(x, y) && !visited[y][x] && mapa[y][x] == '#') {
						visited[y][x] = true;
						kolejka.enqueue({ x, y, p.dystans + 1});
					} else if (is_valid(x, y) && mapa[y][x] == '*' && !(y == startY && x == startX)) {
						/*miasta[idx]->sasiedzi->add(nazwa(x, y), p.dystans);*/
						/*cout << nazwa(x, y).getString() << " -> " << p.dystans << " ";*/

						miasta.miasta[idx].sasiedzi.add(nazwa(x, y), p.dystans);
					}
				}
			}
			
		}
		
	}
	cout << nazwa(startX, startY).getString() << " ->";
	miasta.miasta[idx].sasiedzi.printList();
	cout << endl;

	for (int i = 0; i < h; i++) {
		delete[] visited[i];
	}
	delete[] visited;
}