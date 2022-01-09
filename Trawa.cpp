#include "Trawa.h"

using namespace std;
Trawa::Trawa() {
	
}

Trawa::Trawa(int y, int x){
	this->x = x;
	this->y = y;
	this->strength = 0;
	this->initiative = 0;
	this->name = "Trawa";
	this->is_plant = true;
}

Trawa::~Trawa() {

}

void Trawa::rysowanie() {
	cout << "T";
}
