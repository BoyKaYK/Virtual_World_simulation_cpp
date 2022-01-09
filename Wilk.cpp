#include "Wilk.h"
#include <iostream>


using namespace std;

Wilk::Wilk() {
	
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
	cout << "W";
}