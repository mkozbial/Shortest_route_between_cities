#define _ALLOW_RTCc_IN_STL
#include <iostream>
#include "Mapa.h"

using namespace std;

int main()
{
	int w, h, q;
	cin >> w >> h;

	Mapa* mapaMiast = new Mapa(w, h);
	mapaMiast->wczytajMape();
	system("cls"); //usunac
	mapaMiast->wypiszMape();
	mapaMiast->znajdzMiasta();
	mapaMiast->znajdzSasiadow();
	cin >> q;
	mapaMiast->wykonajPolecenia(q, mapaMiast->miasta);

	return 0;
}