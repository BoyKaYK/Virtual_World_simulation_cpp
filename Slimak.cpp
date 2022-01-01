#include "Slimak.h"
#include <iostream>

Slimak::Slimak() {
	this->strength = 1;
	this->initiative = 1;
	this->name = "Slimak";
}

Slimak::Slimak(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 1;
	this->initiative = 1;
	this->name = "Slimak";
}

Slimak::~Slimak() {

}

void Slimak::akcja() {
	short kierunek_ruchu;
	int x_dir = 0, y_dir = 0;
	bool mozna_wykonac = false;
	bool zyje = true;
	bool dostepne_kierunki[4] = { 1 , 1, 1 , 1 };
	if (rand() % 10 == 0) {
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
			

			int ctr = 0;
			for (int j = 0; j < 4; j++) {
				if (dostepne_kierunki[j] == false) {
					ctr += 1;
				}
			}
			if (ctr == 4) {
				zyje = false;
				break;
			}

			if (swiat->is_border(x_dir, y_dir, swiat->get_rozmiar_y(), swiat->get_rozmiar_x())) {
				dostepne_kierunki[kierunek_ruchu] = false;
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
				if (oponent->get_strength() > this->strength + 1) {
					dostepne_kierunki[kierunek_ruchu] = false;
					continue;
				}
				bool reakcja = oponent->reakcja_na_atak(this);
				if (!reakcja) {
					zyje = this->kolizja(oponent);
				}
				else {
					zyje = false;
				}
				mozna_wykonac = true;
			}
			else {
				mozna_wykonac = true;
			}
		}
		if (zyje) {

			swiat->organizmy_swiat[y_dir][x_dir] = true;
			swiat->organizmy_swiat[y][x] = false;

			this->x = x_dir;
			this->y = y_dir;
		}

	}
}

void Slimak::rysowanie() {
	std::cout << "S";
}