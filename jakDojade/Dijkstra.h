#pragma once
#include "Wektor.h"
#include "Kolejka.h"

void dijkstra(Wektor& miasta, int start, int koniec) {
    const int INF = 1e9;

    int n = miasta.getSize();
    double* dist = new double[n];
    int* prev = new int[n];
    
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;

    Kolejka kolejka;
    kolejka.enqueue(punkt(miasta.miasta[start].getWspolrzedne().getX(), miasta.miasta[start].getWspolrzedne().getY(), 0));

    while (!kolejka.isEmpty()) {
        punkt u = kolejka.front();
        kolejka.dequeue();
        int idx = miasta.findIndex(u);
        if (idx > -1) {
            for (int i = 0; i < miasta.miasta[idx].sasiedzi.getSize(); i++) {
                int v = -1;
                for (int j = 0; j < n; j++) {
                    if (miasta.findIndex(u) >= 0) {
                        if (miasta.miasta[j].getNazwa() == miasta.miasta[idx].sasiedzi.getMiasto(i)) {
                            v = j;
                            break;
                        }
                    }
                }
                if (v == -1) continue;

                double w = miasta.miasta[idx].sasiedzi.getDistance(i);
                if (dist[idx] + w < dist[v]) {
                    dist[v] = dist[idx] + w;
                    prev[v] = u.getX();
                    kolejka.enqueue(punkt(miasta.miasta[v].getWspolrzedne().getX(), miasta.miasta[v].getWspolrzedne().getY(), dist[v]));
                }
            }
        }
    }
    std::cout << "Najkrotsza sciezka z " << miasta.miasta[start].getNazwa().getString() << " do " << miasta.miasta[koniec].getNazwa().getString() << " wynosi " << dist[koniec] << std::endl;
}
