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

    void pushBack(const Miasto& m);
    void popBack();
    int getRozmiar() const;
    bool czyPusty() const;
    void clear();

    Wektor& operator=(const Wektor& other);

    int znajdzIdx(punkt p) const;
    int znajdzIdx(String a) const;
};
