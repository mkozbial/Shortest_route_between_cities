#include <iostream>
#include "Mapa.h"

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

	return 0;
}