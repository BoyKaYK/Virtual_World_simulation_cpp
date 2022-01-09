#pragma once


#include <string>
using namespace std;

class Swiat;

class Organizm {

protected:
	Swiat* swiat;
	int strength;
	int initiative;
	int x, y;
	string name;

public:
	virtual void akcja() = 0;
	virtual bool kolizja(Organizm* z_kim) = 0;
	virtual void rysowanie() = 0;
	void set_koordynaty(int x, int y);

	//void normalny_ruch();
	virtual bool reakcja_na_atak(Organizm* atakujacy);
	virtual void byc_zjedzonym(Organizm* jedzacy);

	int	get_strength() const;
	int get_initiative() const;
	
	int get_x() const;
	int get_y() const;
	string get_name() const;
	void add_strength(int x);
	void set_strength(int strength);

	bool is_plant = false;

	void set_swiat(Swiat* swiat);
	Swiat* get_swiat() const;
	virtual ~Organizm();
};

#include "Swiat.h"