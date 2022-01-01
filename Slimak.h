#pragma once
#include "Zwierze.h"
class Slimak : public Zwierze {
public:
	Slimak();
	Slimak(int y, int x);
	~Slimak();
	void akcja();
	void rysowanie();
};