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

//Miasto Wektor::operator[](int index) {
//    return miasta[index];
//}

//const Miasto& Wektor::operator[](int index) const {
//    return miasta[index];
//}

int Wektor::getSize() const {
    return liczbaMiast;
}

bool Wektor::isEmpty() const {
    return liczbaMiast == 0;
}

void Wektor::clear() {
    liczbaMiast = 0;
}

//Wektor& Wektor::operator=(const Wektor& other) {
//    if (this != &other) {
//        delete[] miasta;
//        liczbaMiast = other.liczbaMiast;
//        pojemnosc = other.pojemnosc;
//        miasta = new Miasto[pojemnosc];
//        for (int i = 0; i < liczbaMiast; i++) {
//            miasta[i] = other.miasta[i];
//        }
//        sasiedzi = other.sasiedzi;
//    }
//    return *this;
//}
//
//void Wektor::dodajSasiada(const Miasto& m, int odleglosc) {
//    sasiedzi.add(m, odleglosc); // add the new neighbor to the end of the list
//}
//
//void Wektor::usunSasiada(const Miasto& m) {
//    for (int i = 0; i < sasiedzi.getSize(); i++) {
//        if (sasiedzi.getMiasto(i).getNazwa() == m.getNazwa()) {
//            sasiedzi.remove(i); // remove the neighbor from the list
//            break;
//        }
//    }
//}
 