#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Slimak.h"
#include "Komar.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Ciern.h"


class Launch {
	int rozm_x, rozm_y;
	Swiat* swiat;
	std::string load_world_input;

	bool simulation_running = true;
	bool load_world_bool = false;

public:

	Launch();

	void game();
	void empty_world();
	void main_menu();
	void set_simulation_running(bool set);

	~Launch();
};

