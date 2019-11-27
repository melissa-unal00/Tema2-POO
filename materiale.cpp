#include "materiale.h"
#include <iostream>
#include <cstdlib>
#inclide <cstring>
using namespace std;

istream & operator>>(istream& in,materiale& y)
{
    in>>y.name>>y.cost;
    return in;
}
ostream & operator<<(ostream& out,materiale& y)
{
    out<<y.name<<y.cost;
    return out;
}

materiale::materiale(char nume[32], int cst)
{
	strcpy(name, nume);
	cost = cst;
};
lista<materiale> materiale::mats;


void materiale::adauga_materiale(char nume[32], int cst) {

	mats.adauga(new materiale(nume, cst));
}


materiale::materiale() {
}


materiale *materiale::gaseste(char input[32]) {
	lista<materiale> *iter = &mats;
	input = strlwr(input);
	int stop = 0;
	if (iter->ths)
	{
		do {
			if (strcmp(input, strlwr(iter->ths->name)) == 0) {
				return iter->obiect();
			}
			if (iter->next) { iter = iter->next; }else{
				stop = 1;
			}

		} while (stop == 0);
	}
	else
	{
		if (iter->next)
		{
			iter = iter->next;
			do {
				if (strcmp(input, strlwr(iter->ths->name)) == 0)
                    {
                        return iter->obiect();
                    }
				if (iter->next)
                    {
                        iter = iter->next;
                    }
                else{
                        stop = 1;
                    }

                }
			while (stop == 0);
		}
		else return 0;
		//throw "Materialul nu exista.";
	}

	return 0;
}
