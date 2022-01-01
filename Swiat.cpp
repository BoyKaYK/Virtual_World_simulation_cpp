#include "Swiat.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

Swiat::Swiat(int rozmiar_x, int rozmiar_y) {
	liczba_organizmow = 0;
	rozmiar_swiata_y = rozmiar_y;
	rozmiar_swiata_x = rozmiar_y;

	organizmy_swiat = new bool* [rozmiar_swiata_y];
	for (int i = 0; i < rozmiar_swiata_y; i++) {
		organizmy_swiat[i] = new bool[rozmiar_swiata_x];
		for (int j = 0; j < rozmiar_swiata_x; j++) {
			organizmy_swiat[i][j] = false;
		}
	}
	srand(time(NULL));

}

void Swiat::wykonaj_ture() {
	dodaj_licznik_tur();
	sortuj_wektor();
	int liczba_organizmow_temp = this->liczba_organizmow;
	for (std::size_t i = 0; i < liczba_organizmow; ++i) {
		this->organizmy[i]->akcja();
		if (zmniejszona_liczba_organizmow) {
			liczba_organizmow_temp -= 1;
			i -= 1;
			zmniejszona_liczba_organizmow = false;
		}
		

	}
	sortuj_wektor();
	
	this->rysuj_swiat();
	
	tura_swiata += 1;
}

bool Swiat::is_border(int x, int y, int r_y, int r_x) {
	if ((y <= -1 || y >= r_y) || (x <= -1 || x >= r_x)) {
		return true;
	}
	else {
		return false;
	}
}

void Swiat::rysuj_swiat() {

	for (int i = -1; i < rozmiar_swiata_y + 1; i++) {
		
		std::cout << "  ";
		
		std::cout << "  ";
		for (int j = -1; j < rozmiar_swiata_x + 1; j++) {
			bool narysowano_organizm = false;
			if (is_border(i, j, rozmiar_swiata_y, rozmiar_swiata_x)) {
				std::cout << '*';
			}
			else {
				if (organizmy_swiat[i][j]) {
					//std::cout << "X";
				}
			}
			for (int q = 0; q < liczba_organizmow; q++) {
				if (organizmy[q]->get_y() == i && organizmy[q]->get_x() == j) {
					organizmy[q]->rysowanie();
					narysowano_organizm = true;
				}
			}
			if (!narysowano_organizm && !is_border(i, j, rozmiar_swiata_y, rozmiar_swiata_x)) {
				std::cout << ' ';
			}
			std::cout << ' ';
		}
		std::cout << '\n';
	}
}

bool operator<(const Organizm& a, const Organizm& b) {
	if (a.get_initiative() != b.get_initiative()) {
		return a.get_initiative() > b.get_initiative();
	}
	else {
		return a.get_strength() > b.get_strength();
	}
}

bool compare(Organizm* a, Organizm* b) {
	if (a->get_initiative() != b->get_initiative()) {
		return a->get_initiative() > b->get_initiative();
	}
	else {
		return a->get_strength() > b->get_strength();
	}
}

void Swiat::sortuj_wektor() {
	std::sort(organizmy.begin(), organizmy.end(), compare);
}

void Swiat::dodaj_organizm(Organizm* org) {
	org->set_swiat(this);
	organizmy.push_back(org);
	this->liczba_organizmow += 1;
	this->organizmy_swiat[org->get_y()][org->get_x()] = true;
}

void Swiat::dodaj_organizm(Organizm* org, bool front) {
	org->set_swiat(this);
	organizmy.insert(organizmy.begin(), 1, org);
	this->liczba_organizmow += 1;
	this->organizmy_swiat[org->get_y()][org->get_x()] = true;
}

void Swiat::usun_organizm(Organizm* org) {
	std::vector<Organizm*>::iterator itr;
	itr = std::find(organizmy.begin(), organizmy.end(), org);

	if (itr != organizmy.end()) {
		this->organizmy_swiat[org->get_y()][org->get_x()] = false;

		organizmy.erase(itr);
		this->liczba_organizmow -= 1;
		//delete org;
	}

}

void Swiat::print_organizmy() {
	sortuj_wektor();

	tabulate::Table tabela_print;

	tabela_print.add_row({ "Nazwa", "X.point", "Y.point", "Inicjatywa", "Sila" });


	for (int i = 0; i < liczba_organizmow; i++) {
		//std::cout << organizmy[i]->get_name() << " x = " << organizmy[i]->get_x() << " y = " << organizmy[i]->get_y() << " age = "<< organizmy[i]->get_age() <<'\n';
		tabela_print.add_row({ organizmy[i]->get_name(), std::to_string(organizmy[i]->get_x()), std::to_string(organizmy[i]->get_y()), std::to_string(organizmy[i]->get_initiative()), std::to_string(organizmy[i]->get_strength())});
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

	std::cout << tabela_print << '\n';
}


void Swiat::dodaj_licznik_tur() {
	std::string tura = "TURA " + std::to_string(tura_swiata);
	tabela_wydarzen.add_row({ tura ,  " ", " ", " ", " ", " ", " ", " " });
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

Swiat::~Swiat() {
	for (int i = 0; i < rozmiar_swiata_y; i++) {
		delete[] organizmy_swiat[i];
	}
	delete[] organizmy_swiat;
}