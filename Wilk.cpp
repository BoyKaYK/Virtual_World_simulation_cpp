#include "Wilk.h"
#include <iostream>

Wilk::Wilk() {
	//std::cout << "konstruktor wilka\n";
	this->strength = 9;
	this->initiative = 5;
	
	this->name = "Wilk";
}
Wilk::Wilk(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 9;
	this->initiative = 5;
	
	this->name = "Wilk";

}
Wilk::~Wilk() {

}

void Wilk::rysowanie() {
	std::cout << "W";
}