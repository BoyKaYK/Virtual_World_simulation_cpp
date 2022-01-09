#pragma once
#include <vector>
#include "Organizm.h"
#include "tabulate.hpp"

using namespace std;

class Swiat {

	int rozmiar_swiata_y;
	int tura_swiata = 0;

public:
	vector<Organizm*> organizmy; //wektor z organizmow

	tabulate::Table tabela_tur;
	
	bool** organizmy_swiat; // sprawdzenie 

	int liczba_organizmow;
	Swiat(int rozmiar_x, int rozmiar_y);
	void wykonaj_ture();
	void rysuj_swiat();
	void sortuj_wektor();
	bool zmniejszona_liczba_organizmow = false;
	bool zwiekszona_liczba_organizmow = false;

	void dodaj_organizm(Organizm* org);
	void dodaj_organizm(Organizm* org, bool front); //
	void usun_organizm(Organizm* org);

	void print_organizmy();
	
	void licznik_tur();

	bool koniec = false;
	
	int get_rozmiar_y() const;
	int get_rozmiar_x() const;
	void set_rozmiar_x(int n);
	void set_rozmiar_y(int n);
	int get_tura() const;
	void set_tura(int tura);

	bool is_border(int x, int y, int r_y, int r_x); // is granica swiata 

	~Swiat();
};
