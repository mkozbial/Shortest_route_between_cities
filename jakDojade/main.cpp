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
	//for (int i = 0; i < mapaMiast->miasta.getRozmiar(); i++) {
	//	cout << mapaMiast->miasta.miasta[i].getNazwa().getString() << " sdds ";
	//	cout << mapaMiast->miasta.miasta[i].sasiedzi.getRozmiar() << endl;
	//	mapaMiast->miasta.miasta[i].sasiedzi.printList();
	//}
	cin >> k;
	
	if(k > 0)
		mapaMiast->dodajLoty(k);
	
	cin >> q;

	mapaMiast->wykonajPolecenia(q, mapaMiast->miasta);



	
	return 0;
}