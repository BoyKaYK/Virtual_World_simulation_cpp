#include "Swiat.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

Swiat::Swiat(int rozmiar_x, int rozmiar_y) {
	liczba_organizmow = 0;
	rozmiar_swiata_y = rozmiar_y;
	
	
	organizmy_swiat = new bool* [rozmiar_swiata_y];
	for (int i = 0; i < rozmiar_swiata_y; i++) {
		organizmy_swiat[i] = new bool[rozmiar_swiata_y];
		for (int j = 0; j < rozmiar_swiata_y; j++) {
			organizmy_swiat[i][j] = false; // tworzymy pusty swiat o rozmiarach rozmiar_y ,rozmiar_y
		}
		// kazdy punkt macierzy == false (nikim niezajety)
	}


	srand(time(NULL));

}
void Swiat::licznik_tur() {

	cout << '\t' << "TURA " << tura_swiata + 1 << '\n';
}

int Swiat::get_rozmiar_y() const {
	return rozmiar_swiata_y;
}
int Swiat::get_rozmiar_x() const {
	return rozmiar_swiata_y;
}

void Swiat::set_rozmiar_x(int n) {
}

void Swiat::set_rozmiar_y(int n) {
}

int Swiat::get_tura() const
{
	return tura_swiata;
}

void Swiat::set_tura(int tura) {
	this->tura_swiata = tura;
}

void Swiat::wykonaj_ture() {
	licznik_tur();  // wypisz ture
	sortuj_wektor(); // pierwszy kto ma > initiative
	int liczba_organizmow_temp = this->liczba_organizmow; // liczba w tej turze 
	for (size_t i = 0; i < liczba_organizmow; ++i) {
		this->organizmy[i]->akcja(); // akcja dla kazdego , po sortowanemu wektorowi
		if (zmniejszona_liczba_organizmow) { // if someone killed
			liczba_organizmow_temp -= 1;
			i -= 1;
			zmniejszona_liczba_organizmow = false;
		}
		

	}
	sortuj_wektor(); // sortowania po akcja()
	
	this->rysuj_swiat(); // ta tura !
	
	tura_swiata += 1;
}

bool Swiat::is_border(int x, int y, int r_y, int r_x) { // granica 
	if ((y <= -1 || y >= r_y) || (x <= -1 || x >= r_x)) {
		return true;
	}
	else {
		return false;
	}
}

void Swiat::rysuj_swiat() {

	for (int i = -1; i < rozmiar_swiata_y + 1; i++) {
		
		cout << "  ";
		
		cout << "  ";

		//cout << "  ";
		for (int j = -1; j < rozmiar_swiata_y + 1; j++) {
			bool jest_organizm = false;
			if (is_border(i, j, rozmiar_swiata_y, rozmiar_swiata_y)) { // granica z *
				cout << '*';
			}
			for (int q = 0; q < liczba_organizmow; q++) { // sprawdzam czy rysowac organizm
				if (organizmy[q]->get_y() == i && organizmy[q]->get_x() == j) { 
					organizmy[q]->rysowanie(); // przechodzimy wektor organizmow
					jest_organizm = true;
				}
			}
			if (!jest_organizm && !is_border(i, j, rozmiar_swiata_y, rozmiar_swiata_y)) {
				cout << ' '; // puste pola 
			}
			cout << ' ';
		}
		cout << '\n';
	}
}

bool operator<(const Organizm& a, const Organizm& b) { // przeciaz operator 
	if (a.get_initiative() != b.get_initiative()) {
		return a.get_initiative() > b.get_initiative();
	}
	else {
		return a.get_strength() > b.get_strength();
	}
}

bool compare(Organizm* a, Organizm* b) { // comparator initiative or strenght dla sortowania .
	if (a->get_initiative() != b->get_initiative()) {
		return a->get_initiative() > b->get_initiative();
	}
	else {
		return a->get_strength() > b->get_strength();
	}
}

void Swiat::sortuj_wektor() {
	sort(organizmy.begin(), organizmy.end(), compare); // sortujemy za initiative . 
}

void Swiat::dodaj_organizm(Organizm* org) {
	org->set_swiat(this);
	organizmy.push_back(org);   // nowy element na koniec wektora
	this->liczba_organizmow += 1;
	this->organizmy_swiat[org->get_y()][org->get_x()] = true; // na tym x y jest organizm
}

void Swiat::dodaj_organizm(Organizm* org, bool front) {
	org->set_swiat(this);
	organizmy.insert(organizmy.begin(), 1, org); // inserting *org na poczatek 1 raz
	this->liczba_organizmow += 1;
	this->organizmy_swiat[org->get_y()][org->get_x()] = true;
}

void Swiat::usun_organizm(Organizm* org) {
	vector<Organizm*>::iterator itr;
	itr = find(organizmy.begin(), organizmy.end(), org); //szukam *org z wektora 

	if (itr != organizmy.end()) {
		this->organizmy_swiat[org->get_y()][org->get_x()] = false; // na tym x y pusto 

		organizmy.erase(itr); // delete org
		this->liczba_organizmow -= 1;
		
	}

}

void Swiat::print_organizmy() { //  z tabulate
	sortuj_wektor();

	tabulate::Table tabela_print;

	tabela_print.add_row({ "Nazwa", "X.point", "Y.point", "Inicjatywa", "Sila" });


	for (int i = 0; i < liczba_organizmow; i++) {
		tabela_print.add_row({ organizmy[i]->get_name(), to_string(organizmy[i]->get_x()), to_string(organizmy[i]->get_y()), to_string(organizmy[i]->get_initiative()), to_string(organizmy[i]->get_strength())});
	}
	tabela_print[0].format()
		.padding_top(1)
		.padding_bottom(1)
		.font_align(tabulate::FontAlign::center)
		.font_style({ tabulate::FontStyle::underline })
		.font_background_color(tabulate::Color::green);
	tabela_print.column(0).format()
		.font_color(tabulate::Color::red);
	tabela_print[0][0].format()
		.font_color(tabulate::Color::red);

	cout << tabela_print << '\n';
}

Swiat::~Swiat() {
	for (int i = 0; i < rozmiar_swiata_y; i++) {
		delete[] organizmy_swiat[i];
	}
	delete[] organizmy_swiat;
}