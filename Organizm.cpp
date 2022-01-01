#include "Organizm.h"
#include <iostream>
#include "Owca.h"
#include "Wilk.h"


void Organizm::set_swiat(Swiat* swiat) {
	this->swiat = swiat;
}

Swiat* Organizm::get_swiat() const {
	return swiat;
}

Organizm::~Organizm() {

}

void Organizm::normalny_ruch() {
	short kierunek_ruchu;
	int x_dir = 0, y_dir = 0;
	bool mozna_wykonac = false;
	bool zyje = true;

	while (!mozna_wykonac) {
		kierunek_ruchu = std::rand() % 4;
		//std::cout << kierunek_ruchu << '\n';
		if (kierunek_ruchu == 0) { // gora
			x_dir = this->x;
			y_dir = this->y - 1;
		}
		else if (kierunek_ruchu == 1) { //prawo
			x_dir = this->x + 1;
			y_dir = this->y;
		}
		else if (kierunek_ruchu == 2) { //dol
			x_dir = this->x;
			y_dir = this->y + 1;
		}
		else if (kierunek_ruchu == 3) { //lewo
			x_dir = this->x - 1;
			y_dir = this->y;
		}

		if (swiat->is_border(x_dir, y_dir, swiat->get_rozmiar_y(), swiat->get_rozmiar_x())) {
			continue;
		}
		else if (swiat->organizmy_swiat[y_dir][x_dir]) { // kolizja
			//std::cout << "kolizja " << this->name << ' ' << this->x << ' ' << this->y << " z " << x_dir << ' ' << y_dir <<'\n';
			Organizm* oponent = NULL;
			for (int q = 0; q < swiat->liczba_organizmow; ++q) {
				if (swiat->organizmy[q]->get_x() == x_dir && swiat->organizmy[q]->get_y() == y_dir) {
					oponent = swiat->organizmy[q];
					break;
				}
			}
			zyje = this->kolizja(oponent);
			mozna_wykonac = true;
		}
		else {
			mozna_wykonac = true;
		}
	}
	if (zyje) {
		//std::cout << this->name << " kierunek ruchu " << x_dir << ' ' << y_dir << '\n';
		swiat->organizmy_swiat[y_dir][x_dir] = true;
		swiat->organizmy_swiat[y][x] = false;

		this->x = x_dir;
		this->y = y_dir;
	}
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
