#include "Miasto.h"

Miasto::Miasto() {
	nazwa = "";
	wspolrzedne.x = 0;
	wspolrzedne.y = 0;
}

Miasto::Miasto(String nazwa, punkt wspolrzedne) {
	this->nazwa = nazwa;
	this->wspolrzedne = wspolrzedne;
}

String Miasto::getNazwa() const {
	return nazwa;
}

punkt Miasto::getWspolrzedne() const {
	return wspolrzedne;
}