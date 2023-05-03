#pragma once
#include "punkt.h"
#include "String.h"
#include "Lista.h"

using namespace std;

class Miasto {
private:



public:
	String nazwa;
	punkt wspolrzedne;
	Lista sasiedzi;
	Miasto();
	Miasto(String nazwa, punkt wspolrzedne);

	String getNazwa() const;
	punkt getWspolrzedne() const;
	Lista getSasiedzi() const;

	void dodajSasiada(const String m, int odleglosc);
};