#pragma once
#include "Kolejka.h"


void dijkstra(Wektor& miasta, int miastoStartowe, int cel, String typ) {

    const int max = 1e9;
    int n = miasta.getRozmiar();
    int* odleglosci = new int[n];
    int* poprzedni = new int[n];

    for (int i = 0; i < n; i++) {
        odleglosci[i] = max;
        poprzedni[i] = -1;
    }

    odleglosci[miastoStartowe] = 0;

    Kolejka kolejka;
    kolejka.enqueue(punkt(miasta.miasta[miastoStartowe].getWspolrzedne().getX(), miasta.miasta[miastoStartowe].getWspolrzedne().getY(), 0));

    while (!kolejka.czyPusty()) {

        punkt obecneMiasto = kolejka.przedni();
        kolejka.dequeue();
        int idx = miasta.znjadzIdx(obecneMiasto);

        if (idx > -1) {

            for (int i = 0; i < miasta.miasta[idx].sasiedzi.getRozmiar(); i++) {
                int sasiadIdx = -1;

                for (int j = 0; j < n; j++) {

                    if (miasta.miasta[j].getNazwa() == miasta.miasta[idx].sasiedzi.getMiasto(i)) {
                        sasiadIdx = j;
                        break;
                    }
                }

                if (sasiadIdx == -1) continue;
                int odlegloscDoSasiada = miasta.miasta[idx].sasiedzi.getDystans(i);

                if (odleglosci[idx] + odlegloscDoSasiada < odleglosci[sasiadIdx]) {
                    odleglosci[sasiadIdx] = odleglosci[idx] + odlegloscDoSasiada;
                    poprzedni[sasiadIdx] = miasta.znjadzIdx(obecneMiasto);
                    kolejka.enqueue(punkt(miasta.miasta[sasiadIdx].getWspolrzedne().getX(), miasta.miasta[sasiadIdx].getWspolrzedne().getY(), odleglosci[sasiadIdx]));
                }
            }
        }
    }
  
    Lista sciezka;

    int idx = cel;
    if (typ == "0") {
        cout << odleglosci[cel] << endl;
    }
    else if (typ == "1") {
        cout << odleglosci[cel] << " ";
        while (idx != miastoStartowe) {

            sciezka.dodaj(miasta.miasta[idx].getNazwa(), odleglosci[idx]);
            idx = poprzedni[idx];

        }

        for (int i = sciezka.getRozmiar() - 1; i >= 1; i--) {
            cout << sciezka.getMiasto(i).getString() << " ";
        }
        cout << endl;
       
    }
    


    delete[] odleglosci;
    delete[] poprzedni;
}

