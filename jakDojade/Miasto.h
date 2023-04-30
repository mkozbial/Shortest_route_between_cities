#pragma once
#include "punkt.h"
#include "String.h"
using namespace std;

class Miasto {
private:
	String nazwa;
	punkt wspolrzedne;
public:
	Miasto();
	Miasto(String nazwa, punkt wspolrzedne);
	String getNazwa() const;
	punkt getWspolrzedne() const;
};