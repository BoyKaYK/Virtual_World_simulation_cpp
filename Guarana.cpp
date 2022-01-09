#include "Guarana.h"
#include <iostream>

Guarana::Guarana(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 0;
	this->initiative = 0;
	this->name = "Guarana";
	this->is_plant = true;
}

Guarana::~Guarana() {
	
}

void Guarana::rysowanie() {
	cout << "G";
}

void Guarana::byc_zjedzonym(Organizm* jedzacy) {
	swiat->usun_organizm((Organizm*)this);
	swiat->zmniejszona_liczba_organizmow = true;
}
