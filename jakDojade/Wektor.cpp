#include "Wektor.h"

Wektor::Wektor() {
    liczbaMiast = 0;
    pojemnosc = 1;
    miasta = new Miasto[pojemnosc];
}

Wektor::Wektor(const Wektor& other) {
    liczbaMiast = other.liczbaMiast;
    pojemnosc = other.pojemnosc;
    miasta = new Miasto[pojemnosc];
    for (int i = 0; i < liczbaMiast; i++) {
        miasta[i] = other.miasta[i];
    }
}

Wektor::~Wektor() {
    delete[] miasta;
}

void Wektor::push_back(const Miasto& m) {
    if (liczbaMiast == pojemnosc) {
        pojemnosc *= 2;
        Miasto* newData = new Miasto[pojemnosc];
        for (int i = 0; i < liczbaMiast; i++) {
            newData[i] = miasta[i];
        }
        delete[] miasta;
        miasta = newData;
    }
    miasta[liczbaMiast++] = m;
}

void Wektor::pop_back() {
    if (liczbaMiast > 0) {
        liczbaMiast--;
    }
}

int Wektor::getSize() const {
    return liczbaMiast;
}

bool Wektor::isEmpty() const {
    return liczbaMiast == 0;
}

void Wektor::clear() {
    liczbaMiast = 0;
}

int Wektor::findIndex(punkt p) const {
    for (int i = 0; i < liczbaMiast; i++) {
        if (miasta[i].getWspolrzedne().getX() == p.x && miasta[i].getWspolrzedne().getY() == p.y) {
            return i;
        }
    }
    return -1; // indicates city not found
}

 