#include "Zwierze.h"
class Komar : public Zwierze {
public:
	Komar(int y, int x);
	~Komar();
	void rysowanie();
	void akcja();
	void add_sila(int x);
	
};