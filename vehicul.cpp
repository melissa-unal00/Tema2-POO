#include "vehicul.h"
#include <cstdlib>
#inclide <cstring>
#include <iostream>
using namespace std;

istream & operator>>(istream& in,vehicul& y)
{
    in>>y.name>>y.cost;
    return in;
}
ostream & operator<<(ostream& out,vehicul& y)
{
    out<<y.name<<y.cost;
    return out;
}

void vehicul::damage()
{
	m.damage(tag);  //m->motor
	f.damage(tag);  //f->frane
	d.damage(tag);  //d->directie
	c.damage(tag);  //d->caroserie
	e.damage(tag);  //e->emisii
};

void vehicul::diagnostic()
{
	m.diagnostic();  //m->motor
	f.diagnostic();  //f->frane
	d.diagnostic();  //d->directie
	c.diagnostic();  //d->caroserie
	e.diagnostic();  //e->emisii
};

void vehicul::operator=(const vehicul &v)
{
	tag=v.tag;
	strcpy(name, v.name);
	an = v.an;
}
