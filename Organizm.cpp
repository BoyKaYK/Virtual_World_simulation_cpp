#include "Organizm.h"
#include <iostream>

using namespace std;

void Organizm::set_swiat(Swiat* swiat) {
	this->swiat = swiat;
}

Swiat* Organizm::get_swiat() const {
	return swiat;
}

Organizm::~Organizm() {

}

bool Organizm::reakcja_na_atak(Organizm* atakujacy) {
	return false;
}

void Organizm::byc_zjedzonym(Organizm* jedzacy) {

}


void Organizm::set_koordynaty(int x, int y) {
	swiat->organizmy_swiat[this->x][this->y] = true;
	this->x = x;
	this->y = y;
	swiat->organizmy_swiat[x][y] = true;
}

int	Organizm::get_strength() const {
	return this->strength;
}
int Organizm::get_initiative() const {
	return this->initiative;
}
int Organizm::get_x() const {
	return x;
}
int Organizm::get_y() const {
	return y;
}

std::string Organizm::get_name() const {
	return name;
}

void Organizm::add_strength(int x) {
	this->strength += x;
}

void Organizm::set_strength(int strength) {
	this->strength = strength;
}
