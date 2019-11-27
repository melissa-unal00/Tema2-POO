#include <conio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#inclide <cstring>
#include "vehicul.h"
using namespace std;

//Definim clasa atelier
class atelier
{
protected:
	static vehicul veh;
public:
	static int cost_final;
	static int efort_om;
	atelier();
	~atelier();
	static void primeste(const vehicul &obj);
    static void diagnostic();
    friend istream & operator>>(istream&,atelier&);
    friend ostream & operator<<(ostream&,atelier&);

};

