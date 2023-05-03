#pragma once
#include "Kolejka.h"


void dijkstra(Wektor& miasta, int miastoStartowe, int cel, int typ) {
   

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
        int idx = miasta.znajdzIdx(obecneMiasto);

        if (idx > -1) {
            int rozm = miasta.miasta[idx].sasiedzi.getRozmiar();
            for (int i = 0; i < rozm; i++) {
                int sasiadIdx = -1;
                int indeks = 0;
                for (int j = 0; j < n; j++) {

                    if (miasta.miasta[idx].sasiedzi.head == nullptr) {
                        continue;
                    }
                    Node* curr = miasta.miasta[idx].sasiedzi.head;

                    for (int k = 0; k < i; k++) {

                        if (curr->next == nullptr) {
                            continue;
                        }
                        curr = curr->next;
                    }

                    /*if (miasta.miasta[j].getNazwa() == miasta.miasta[idx].sasiedzi.getMiasto(i))*/
                    if (miasta.miasta[j].nazwa == curr->miasto) {
                        sasiadIdx = j;
                        break;
                    }

                    

                    

                    

                   /* if (miasta.miasta[idx].sasiedzi.head == nullptr) {
                        continue;
                    }

                    Node* curr = miasta.miasta[idx].sasiedzi.head;

                    while(curr != nullptr) {
                
                        if (indeks == i && strcmp(miasta.miasta[j].nazwa.strData, curr->miasto.strData) == 0) {
                            sasiadIdx = j;
                            break;
                        }
                        curr = curr->next;
                        indeks++;
                    }*/

                
                }

                if (sasiadIdx == -1) continue;
                int odlegloscDoSasiada = miasta.miasta[idx].sasiedzi.getDystans(i);

                if (odleglosci[idx] + odlegloscDoSasiada < odleglosci[sasiadIdx]) {
                    odleglosci[sasiadIdx] = odleglosci[idx] + odlegloscDoSasiada;
                    poprzedni[sasiadIdx] = miasta.znajdzIdx(obecneMiasto);

                    kolejka.enqueue(punkt(miasta.miasta[sasiadIdx].getWspolrzedne().getX(), miasta.miasta[sasiadIdx].getWspolrzedne().getY(), odleglosci[sasiadIdx]));
                }
            }
        }
    }
   
    Lista sciezka;

    int idx = cel;
    if (idx == -1) {
        return;
    }
    if (typ == 0) {
        cout << odleglosci[cel] << endl;
    }
    else if (typ == 1) {
        cout << odleglosci[cel] << " ";
        while (idx != miastoStartowe) {
            //cout << "UWAGA: " << poprzedni[idx] << endl;
            sciezka.dodaj(miasta.miasta[idx].getNazwa(), odleglosci[idx]);
            idx = poprzedni[idx];

        }

        for (int i = sciezka.getRozmiar() - 1; i >= 1; i--) {
            cout << sciezka.getMiasto(i).getString() << " ";
        }
        cout << endl;
       
    }
    

    
   /* delete odleglosci;*/
    delete poprzedni;
}

