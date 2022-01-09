#pragma once
#include "Roslina.h"
using namespace std;

class Guarana : public Roslina {
public:
	Guarana(int y, int x);
	~Guarana();
	void rysowanie();
	void byc_zjedzonym(Organizm* jedzacy);
};

