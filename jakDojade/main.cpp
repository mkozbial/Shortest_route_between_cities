#define _ALLOW_RTCc_IN_STL
#include <iostream>
#include "Mapa.h"

using namespace std;

int main()
{
	int w, h, q, k;
	cin >> w >> h;

	Mapa* mapaMiast = new Mapa(w, h);
	mapaMiast->wczytajMape();
	mapaMiast->znajdzMiasta();
	mapaMiast->znajdzSasiadow();
	cin >> k;
	mapaMiast->dodajLoty(k);
	cin >> q;
	mapaMiast->wykonajPolecenia(q, mapaMiast->miasta);
	
	return 0;
}