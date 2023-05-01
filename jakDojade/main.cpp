#define _ALLOW_RTCc_IN_STL
#include <iostream>
#include "Mapa.h"
#include "Dijkstra.h"

using namespace std;

int main()
{
	int w, h;
	cin >> w >> h;

	Mapa* mapaMiast = new Mapa(w, h);
	mapaMiast->wczytajMape();
	system("cls");
	mapaMiast->wypiszMape();
	mapaMiast->znajdzMiasta();
	mapaMiast->znajdzSasiadow();
	mapaMiast->wypiszMiasta();
	dijkstra(mapaMiast->miasta, 0, 1);



	return 0;
}