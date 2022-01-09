#include "Launch.h"
#include "tabulate.hpp"
#include <fstream>

using namespace std;


#define LICZBA_TUR 50

Launch::Launch(){
	main_menu(); // launch konstruktor
	swiat = new Swiat(rozm_x, rozm_y);
	
}
void Launch::empty_world() {
	
	/*Organizm* wilk = new Wilk(0, 1);
	swiat->dodaj_organizm(wilk);


	Organizm* wilk1 = new Wilk(0, 2);
	swiat->dodaj_organizm(wilk1);

	
	Organizm* owca = new Owca(0,2 );
	swiat->dodaj_organizm(owca);

	Organizm* trawa = new Trawa(0, 3);
	swiat->dodaj_organizm(trawa);

	Organizm* lis = new Lis(0, 4);
	swiat->dodaj_organizm(lis);

	Organizm* slimak = new Slimak(0, 5);
	swiat->dodaj_organizm(slimak);
	//swiat->usun_organizm(slimak);

	Organizm* komar = new Komar(0,6);
	swiat->dodaj_organizm(komar);
	//swiat->usun_organizm(komar);

	Organizm* guarana = new Guarana(0,7 );
	swiat->dodaj_organizm(guarana);
	//swiat->usun_organizm(guarana);

	Organizm* ciern = new Ciern(0,8 );
	swiat->dodaj_organizm(ciern);
	//swiat->usun_organizm(ciern);
	*/

	swiat->rysuj_swiat();

	//swiat->print_organizmy();

	cout << "------------\n";
	cout << '\n';

	int next_tura = 1;

	for (int i = 0; i < LICZBA_TUR; i++) {  //urutury 

		if (!swiat->koniec && next_tura != 0) {

			swiat->wykonaj_ture();

			cout << "\n Dla nastepnej tury wpisz '1' \n Dla zakonczenia wpisz '0' ";

			cin >> next_tura;

		}
		else {

			break;
		}
	}

}
void Launch::game() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	cout << " Generuje Swiat ... \n";

		cout << " Geneuje organizmy ...\n";
		const int liczba_wilkow = 5;
		const int liczba_owiec = 4;
		const int liczba_traw = 5;
		const int liczba_lisow = 6;
		const int liczba_slimakow = 3;
		const int liczba_komarow = 5;
		const int liczba_guarany = 3;
		const int liczba_cierni = 3;

		for (int i = 0; i < liczba_wilkow; i++) {
			int wilk_x, wilk_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				wilk_x = rand() % swiat->get_rozmiar_x();
				wilk_y = rand() % swiat->get_rozmiar_y();
				if (!swiat->organizmy_swiat[wilk_y][wilk_x]) {
					mozna_postawic = true;
				}
			}
			Organizm* wilk = new Wilk(wilk_y, wilk_x);
			swiat->dodaj_organizm(wilk);
		}
		for (int i = 0; i < liczba_owiec; i++) {
			int owca_x, owca_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				owca_x = rand() % swiat->get_rozmiar_x();
				owca_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[owca_y][owca_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* owca = new Owca(owca_y, owca_x);
			swiat->dodaj_organizm(owca);
		}
		for (int i = 0; i < liczba_traw; i++) {
			int trawa_x, trawa_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				trawa_x = rand() % swiat->get_rozmiar_x();
				trawa_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[trawa_y][trawa_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* trawa = new Trawa(trawa_y, trawa_x);
			swiat->dodaj_organizm(trawa);
		}
		
		for (int i = 0; i < liczba_lisow; i++) {
			int lis_x, lis_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				lis_x = rand() % swiat->get_rozmiar_x();
				lis_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[lis_y][lis_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* lis = new Lis(lis_y, lis_x);
			swiat->dodaj_organizm(lis);
		}
		for (int i = 0; i < liczba_slimakow; i++) {
			int slimak_x, slimak_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				slimak_x = rand() % swiat->get_rozmiar_x();
				slimak_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[slimak_y][slimak_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* slimak = new Slimak(slimak_y, slimak_x);
			swiat->dodaj_organizm(slimak);
			//swiat->usun_organizm(slimak);
		}
		for (int i = 0; i < liczba_komarow; i++) {
			int komar_x, komar_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				komar_x = rand() % swiat->get_rozmiar_x();
				komar_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[komar_y][komar_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* komar = new Komar(komar_y, komar_x);
			swiat->dodaj_organizm(komar);
			//swiat->usun_organizm(komar);
		}
		for (int i = 0; i < liczba_guarany; i++) {
			int guarana_x, guarana_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				guarana_x = rand() % swiat->get_rozmiar_x();
				guarana_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[guarana_y][guarana_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* guarana = new Guarana(guarana_y, guarana_x);
			swiat->dodaj_organizm(guarana);
			//swiat->usun_organizm(guarana);
		}
		for (int i = 0; i < liczba_cierni; i++) {
			int ciern_x, ciern_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				ciern_x = rand() % swiat->get_rozmiar_x();
				ciern_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[ciern_y][ciern_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* ciern = new Ciern(ciern_y, ciern_x);
			swiat->dodaj_organizm(ciern);
			//swiat->usun_organizm(ciern);
		}
        
		cout << " \n Wygenerowano organizmy : \n";
		//swiat->print_organizmy();
		
		swiat->rysuj_swiat();
		
		
		
		cout << "------------\n";
		cout << '\n';
	
	 
	int next_tura = 1;
	
		for (int i = 0; i < LICZBA_TUR; i++) {  //urutury 
			
			if (!swiat->koniec && next_tura != 0) {
				
				swiat->wykonaj_ture();

				cout << "\n Dla nastepnej tury wpisz '1' \n Dla zakonczenia wpisz '0' ";

				cin >> next_tura;
				
			}
			else {
				
				break;
			}
		}

	

}

void Launch::main_menu() {

	cout << "				  Autor: Yevhenii Kasian 187783	\n\n";

	
	cout << " Wpisz rozmiar swiata :  \n" << '\t';
	
	cin >> rozm_y;

	

}

void Launch::set_simulation_running(bool set) {
	this->simulation_running = set;
}


Launch::~Launch(){
}
