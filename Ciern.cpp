#include "Ciern.h"
#include <iostream>

Ciern::Ciern(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 2;
	this->initiative = 0;
	this->name = "Ciern";
	this->is_plant = true;
}

Ciern::~Ciern() {

}

void Ciern::rysowanie() {
	cout << "C";
}

void Ciern::akcja() {
	
	short sprobuj;
	sprobuj = rand() % 100; // prawdopodobienstwo 10%
	if (sprobuj < 10) {
		rozprzestrzeniaj();
	}
	
}


void Ciern::byc_zjedzonym(Organizm* jedzacy) {
	swiat->usun_organizm((Organizm*)this);
	swiat->zmniejszona_liczba_organizmow = true;
	
}