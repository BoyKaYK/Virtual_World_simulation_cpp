#pragma once
#include "Roslina.h"
using namespace std;
class Ciern : public Roslina {
public:
	Ciern(int y, int x);
	~Ciern();
	void rysowanie();
	void akcja();
	void byc_zjedzonym(Organizm* jedzacy);
};