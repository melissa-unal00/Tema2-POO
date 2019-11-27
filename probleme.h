#include "materiale.h"
#include <iostream>
#include <cstdlib>
#inclide <cstring>
using namespace std;

class ob
{
public:
	materiale *mat;
	int count = 0;
	ob(materiale *mt, int val)
	{
		count = val;
		mat = mt;
	}
	ob() {};
};

class probleme
{
protected:
	char name[256];
	char flags[64];
	int oo = 0;
	lista<ob> listtt;
	virtual void getMat(char src[256]);
public:
	probleme(char nume[256], char flg[64], int oo, char materials[256]);
	probleme();
	~probleme();
	virtual void print();
	virtual bool tag(const char z);
	friend istream & operator>>(istream&,probleme&);
    friend ostream & operator<<(ostream&,probleme&);
};
