#include <conio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#inclide <cstring>
#include "probleme.h"
using namespace std;

template<typename T>
class componente
{
public:
	static lista<probleme> problems;
	lista<probleme> actualProblems;
	virtual void adauga(char nume[256], char flg[64], int mnhrs, char materials[256]= "\n");
	virtual void damage(char flag);
	virtual void diagnostic();
	virtual probleme *get_tag(int n, char z);
	virtual bool tag_valid(char flag);
	static void adauga_probleme(char nume[256], char flg[64], int mnhrs, char materials[256] = "\n");
	friend istream & operator>>(istream&,componente&);
        friend ostream & operator<<(ostream&,componente&);
};

class frane: public componente<frane>
{
public:
	frane() {};
	~frane();
};

class motor: public componente<motor>
{
public:
	motor() {};
	~motor();
};

class directie: public componente<directie>
{
public:

	directie() {};
	~directie();

};

class emisii: public componente<emisii>
{
public:
	emisii() {};
	~emisii();
};

class caroserie : public componente<caroserie>
{
public:

	caroserie() {};
	~caroserie();
};
