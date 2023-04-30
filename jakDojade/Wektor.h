#pragma once
#include "Miasto.h"

class Wektor {
private:
    Miasto* miasta;
    int liczbaMiast;
    int pojemnosc;
public:
    Wektor();
    Wektor(const Wektor& other);
    ~Wektor();
    void push_back(const Miasto& m);
    void pop_back();
    Miasto operator[](int index);
    const Miasto& operator[](int index) const;
    int getSize() const;
    bool isEmpty() const;
    void clear();
    Wektor& operator=(const Wektor& other);
};
