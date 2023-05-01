#pragma once
#include "punkt.h"
#include "String.h"
#include "Lista.h"

using namespace std;

class Miasto {
private:
	String nazwa;
	punkt wspolrzedne;

public:
	LinkedList sasiedzi;
	Miasto();
	Miasto(String nazwa, punkt wspolrzedne);
	String getNazwa() const;
	punkt getWspolrzedne() const;
	LinkedList getSasiedzi() const;
	void dodajSasiada(const String m, int odleglosc);
};