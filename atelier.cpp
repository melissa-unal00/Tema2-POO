#include <conio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#inclide <cstring>
#include "atelier.h"
#include "vehicul.h"
using namespace std;

istream & operator>>(istream& in,atelier& x)
{
    in>>x.veh;
    return in;
}
ostream & operator<<(ostream& out,atelier& x)
{
    out<<x.veh;
    return out;
}

int atelier::cost_final = 0;
int atelier::efort_om = 5;

vehicul atelier::veh = vehicul();

void atelier::primeste(const vehicul &obj)
{
	veh = obj;
	cout<<veh.name;
	veh.damage();
};


void atelier::diagnostic()
{
	veh.diagnostic();
};
