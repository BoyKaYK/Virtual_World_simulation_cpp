#include "Komar.h"
using namespace std;

Komar::Komar(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 1;
	this->initiative = 1;
	this->name = "Komar";
}

Komar::~Komar() {
}

void Komar::rysowanie() {
	std::cout << "K";
}

void Komar::add_sila(int x ) {
	this->strength += x;
	
}

void Komar::akcja() {
	short kierunek_ruchu;
	int x_dir = 0, y_dir = 0;
	bool mozna_wykonac = false;
	bool zyje = true;
	bool dostepne_kierunki[4] = { 1 , 1, 1 , 1 };
	
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
				if (dostepne_kierunki[j] == false) { // otoczenie 
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
				
				Organizm* sasiad = NULL;
				Organizm* sasiad1 = NULL;
				Organizm* sasiad2 = NULL;
				Organizm* sasiad3= NULL;

				for (int q = 0; q < swiat->liczba_organizmow; ++q) {
					if (swiat->organizmy[q]->get_x() == x_dir+1 && swiat->organizmy[q]->get_y() == y_dir) {
						sasiad = swiat->organizmy[q];
						if (sasiad->get_name() == "Komar") {
							this->add_sila(1); // sila +1 jesli komar obok
						}
					}

					else if (swiat->organizmy[q]->get_x() == x_dir-1 && swiat->organizmy[q]->get_y() == y_dir) {
						sasiad1 = swiat->organizmy[q];
						if (sasiad1->get_name() == "Komar") {
							this->add_sila(1);
						}
					}

					else if (swiat->organizmy[q]->get_x() == x_dir && swiat->organizmy[q]->get_y() == y_dir+1) {
						sasiad2 = swiat->organizmy[q];
						if (sasiad2->get_name() == "Komar") {
							this->add_sila(1);
						}
					}

					else if (swiat->organizmy[q]->get_x() == x_dir && swiat->organizmy[q]->get_y() == y_dir-1) {
						sasiad3 = swiat->organizmy[q];
						if (sasiad3->get_name() == "Komar") {
							this->add_sila(1);
						}
					}
					
				}

				Organizm* oponent = NULL;
				for (int q = 0; q < swiat->liczba_organizmow; ++q) {
					if (swiat->organizmy[q]->get_x() == x_dir && swiat->organizmy[q]->get_y() == y_dir) {
						oponent = swiat->organizmy[q];
						break;
					}
				}

				cout << "Kolizja " << this->name << ' ' << this->x << ' ' << this->y << " z " << oponent->get_name() << '\n';

				if (oponent->get_strength() > this->strength) {
					dostepne_kierunki[kierunek_ruchu] = false;
					continue;
				}
				bool reakcja = oponent->reakcja_na_atak(this);
				if (!reakcja) {
					zyje = this->kolizja(oponent);
					if (zyje == false) {
						int szansa = rand() % 2;
						if (szansa == 0) {
							zyje = true;      //50 % na prze¿ycie
							mozna_wykonac = false;
						}
					}
					break;
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

