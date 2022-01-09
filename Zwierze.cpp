#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Slimak.h"
#include "Komar.h"
#include <iostream>

using namespace std;

void Zwierze::akcja() {
	short kierunek_ruchu;
	int x_dir = 0, y_dir = 0;
	bool mozna_wykonac = false;
	bool zyje = true;

	while (!mozna_wykonac) {
		kierunek_ruchu = rand() % 4;
		
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
			Organizm* oponent = NULL;

			for (int q = 0; q < swiat->liczba_organizmow; ++q) {
				if (swiat->organizmy[q]->get_x() == x_dir && swiat->organizmy[q]->get_y() == y_dir) {
					oponent = swiat->organizmy[q]; // przeszukuje wektor i szukam oponenta z x_dir i y_dir
					break;
				}
			}

			cout << "Kolizja " << this->name << ' ' << this->x << ' ' << this->y << " z " << oponent->get_name() << '\n';

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
		
		swiat->organizmy_swiat[y_dir][x_dir] = true; // nowa pozycja 
		swiat->organizmy_swiat[y][x] = false; // poprzednai 

		this->x = x_dir;
		this->y = y_dir;   // przypisujemy nowa pozycje 
	}
}

bool Zwierze::kolizja(Organizm* z_kim) {
	if (this->name == z_kim->get_name()) { // rozmnazanie jesli z soba 
		this->rozmnazaj(z_kim);
		return false;
	}
	else if (z_kim->is_plant) { // jedzenie jesli roslina 
		z_kim->byc_zjedzonym(this);
		return true;
	}
	else { // walka
		if (walka(z_kim)) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Zwierze::walka(Organizm* z_kim) {

	
	if (z_kim == NULL) {
		
		return true;
	}
	
	if (this->strength >= z_kim->get_strength()) {  // kto ma > sile .
		
		swiat->usun_organizm(z_kim);  
		swiat->zmniejszona_liczba_organizmow = true;
		return true;
	}
	else {
		
		swiat->usun_organizm((Organizm*)this);
		swiat->zmniejszona_liczba_organizmow = true;
		return false;
	}
}

void Zwierze::rozmnazaj(Organizm* z_kim) {
	// - szukamy puste miejsce 
	// - if miejsce jest dodajemy organizm 
	// - liczba wszystkich += 1
	bool mozna_wykonac = false;
	int kierunek = 0;
	int x_dir = 0;
	int y_dir = 0;
	while (kierunek != 4) {
		kierunek = rand() % 4;
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
			// szukamy puste miejsce 
		}
		else {
			// new organizm na x_dir  y_dir  ;
			mozna_wykonac = true;
			break;
		}
		kierunek += 1; 
	}
	if (mozna_wykonac) {
		Organizm* urodzony;
		if (this->name == "Owca") {
			urodzony = new Owca(y_dir, x_dir);
		}
		else if (this->name == "Wilk") {
			urodzony = new Wilk(y_dir, x_dir);
		}
		else if (this->name == "Lis") {
			urodzony = new Lis(y_dir, x_dir);
		}
		else if (this->name == "Slimak") {
			urodzony = new Slimak(y_dir, x_dir);
		}
		else if (this->name == "Komar") {
			urodzony = new Komar(y_dir, x_dir);
		}
		else {
			urodzony = new Slimak(y_dir, x_dir);
		}
		swiat->dodaj_organizm(urodzony, 1);
		cout << " Rozmnozono :"<<urodzony->get_name()<< '\n'; // komunikat
		swiat->zwiekszona_liczba_organizmow = true;
		swiat->sortuj_wektor();
	}
}