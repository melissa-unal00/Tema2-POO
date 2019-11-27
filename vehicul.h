#include "lista.h"
#include "componente.h"
#include <cstdlib>
#inclide <cstring>
#include <iostream>
using namespace std;

class vehicul
{
public:
	char name[32];
	char tag;
	int an;
	motor m;
	frane f;
	directie d;
	caroserie c;
	emisii e;
	virtual void damage();
	virtual void diagnostic();
	void operator=(const vehicul &v);
	friend istream & operator>>(istream&,vehicul&);
    friend ostream & operator<<(ostream&,vehicul&);
};

