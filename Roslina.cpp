#include "Roslina.h"
#include "Trawa.h"
#include "Guarana.h"


void Roslina::rozprzestrzeniaj() {
	bool mozna_wykonac = false;
	int kierunek = 0;
	int x_dir = 0;
	int y_dir = 0;
	while (kierunek != 4) {
		kierunek = std::rand() % 4;
		if (kierunek == 0) { // gora
			x_dir = this->x;
			y_dir = this->y - 1;
		}
		else if (kierunek == 1) { //prawo
			x_dir = this->x + 1;
			y_dir = this->y;
		}
		else if (kierunek == 2) { //dol
			x_dir = this->x;
			y_dir = this->y + 1;
		}
		else if (kierunek == 3) { //lewo
			x_dir = this->x - 1;
			y_dir = this->y;
		}

		if (swiat->is_border(x_dir, y_dir, swiat->get_rozmiar_y(), swiat->get_rozmiar_x()) || swiat->organizmy_swiat[y_dir][x_dir]) {

		}
		else {
			//std::cout << "dziecko na " << x_dir << ' ' << y_dir << '\n';
			mozna_wykonac = true;
			break;
		}
		kierunek += 1;
	}
	if (mozna_wykonac) {
		Organizm* dziecko;
		if (this->name == "Trawa") {
			dziecko = new Trawa(y_dir, x_dir);
		}
		/*else if (this->name == "Mlecz") {
			dziecko = new Mlecz(y_dir, x_dir);
		}*/
		else if (this->name == "Guarana") {
			dziecko = new Guarana(y_dir, x_dir);
		}
		/*else if (this->name == "Wilcze Jagody") {
			dziecko = new WilczeJagody(y_dir, x_dir);
		}*/
		else {
			dziecko = new Trawa(y_dir, x_dir);
		}
		swiat->dodaj_organizm(dziecko, 1);
		swiat->zwiekszona_liczba_organizmow = true;
		swiat->sortuj_wektor();
	}
}

bool Roslina::kolizja(Organizm* z_kim) {
	return false;
}

#define SZANSA_ROZPRZESTRZENIANIA 10

void Roslina::akcja() {
	short sprobuj;
	sprobuj = rand() % 100;
	if (sprobuj < SZANSA_ROZPRZESTRZENIANIA) {
		rozprzestrzeniaj();
	}
}

void Roslina::byc_zjedzonym(Organizm* jedzacy) {
	swiat->usun_organizm((Organizm*)this);
	swiat->zmniejszona_liczba_organizmow = true;
}

