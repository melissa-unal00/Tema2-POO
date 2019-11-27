#include "materiale.h"
#include "probleme.h"
#include "lista.h"
#include "componente.h"
#include "atelier.h"
#include "vehicul.h"
#include <conio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#inclide <cstring>
using namespace std;

class masina : public vehicul
{
public:
	masina()
	{
	     tag = 'c';
	     strcpy(name, "Masina");
    }
};

class motocicleta : public vehicul
{
protected:
    char
public:
	motocicleta()
	{
		tag = 'm';
		strcpy(name, "Motocicleta");
	}
};

class bicicleta : public vehicul {
public:
	bicicleta()
	{
		tag = 'b';
		strcpy(name, "Bicicleta");
	}
};


int main()
{
    //Dam noi materialele si problemele
	materiale::adauga_materiale("Cupru", 5);
	materiale::adauga_materiale("Fier", 3);
	materiale::adauga_materiale("Suruburi", 2);
	materiale::adauga_materiale("Ulei", 10);
	materiale::adauga_materiale("placuta1", 5);
	materiale::adauga_materiale("placuta2", 4);
	materiale::adauga_materiale("placuta3", 6);
	materiale::adauga_materiale("placuta4", 7);
	materiale::adauga_materiale("Disc", 15);
	materiale::adauga_materiale("Lant", 5);
	materiale::adauga_materiale("Motor", 40);
	materiale::adauga_materiale("Roata", 10);
	materiale::adauga_materiale("Aripa", 5);
	materiale::adauga_materiale("Capota", 5);
	materiale::adauga_materiale("Vopsea", 5);
	materiale::adauga_materiale("Bara", 5);

	frane::adauga_probleme("Placute fata uzate", "cm", 1, "placuta1;placuta2;suruburi");
	frane::adauga_probleme("Placute spate uzate", "cm", 1, "placuta3;placuta4;suruburi");
	frane::adauga_probleme("Disc uzat", "cm", 1, "disc;suruburi");
	frane::adauga_probleme("Discuri uzate", "c", 2, "disc;suruburi");
	frane::adauga_probleme("Lant tocit", "b", 1, "lant;suruburi");
	frane::adauga_probleme("Lant lipsa", "b", 1, "lant;suruburi");
	frane::adauga_probleme("Defect capital", "cmb", 0);

	motor::adauga_probleme("Nivel ulei scazut", "cm", 1, "ulei;suruburi");
	motor::adauga_probleme("Carburator murdar", "c", 2, "suruburi");
	motor::adauga_probleme("Motor topit", "cm", 5, "motor;suruburi");
	motor::adauga_probleme("Defect capital", "cm", 0);

	directie::adauga_probleme("Ghidon stramb", "mb", 1, "suruburi");
	directie::adauga_probleme("Roata stramba", "cmb", 1, "roata;suruburi");
	directie::adauga_probleme("Defect capital", "cmb", 0);

	emisii::adauga_probleme("Vehiculul arde ulei", "cm", 2, "ulei;suruburi");
	emisii::adauga_probleme("Vehiculul este anterior anului 2000", "cm", 0, "suruburi");
	emisii::adauga_probleme("Defect capital", "cm", 0);

	caroserie::adauga_probleme("Caroserie corodata de rugina", "c", 8, "vopsea;suruburi");
	caroserie::adauga_probleme("Caroserie stramba", "c", 3, "aripa;bara;capota;suruburi");
	caroserie::adauga_probleme("Defect capital", "c", 0);

	int choice;
	cout<<"Se primeste un vehicul";

	//Se alege random vehiculul

	srand(time(NULL));
	choice = rand() % 3 + 1;
	switch (choice)
	{
	case 1:
		atelier::primeste(masina::masina());
		break;
	case 2:
		atelier::primeste(motocicleta::motocicleta());
		break;
	case 3:
		atelier::primeste(bicicleta::bicicleta());
		break;
	default:
		atelier::primeste(masina::masina());
		break;
	}
	atelier::diagnostic();
	cout<<"Total: "<<atelier::cost_final;
	getch();
	return 0;
}
