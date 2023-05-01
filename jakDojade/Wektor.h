#pragma once
#include "Miasto.h"

class Wektor {
public:
    Miasto* miasta;
    int liczbaMiast;
    int pojemnosc;
    Wektor();
    Wektor(const Wektor& other);
    ~Wektor();
    void push_back(const Miasto& m);
    void pop_back();
  /*  Miasto operator[](int index);*/
   /* const Miasto& operator[](int index) const;*/
    int getSize() const;
    bool isEmpty() const;
    void clear();
    Wektor& operator=(const Wektor& other);
    int findIndex(punkt p) const;
    //void dodajSasiada(const Miasto& m, int odleglosc);
    //void usunSasiada(const Miasto& m);
    //void wyswietlSasiadow() const;
};
