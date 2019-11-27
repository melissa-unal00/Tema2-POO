#include "lista.h"
#include "materiale.h"
#include <cstdlib>
#inclide <cstring>
using namespace std;

class materiale
{
protected:
	materiale(char nume[32], int cst);
public:
	static lista<materiale> mats;
	char name[32];
    int cost;
	static void adauga_materiale(char nume[32], int cst);
	materiale();
	static materiale *gaseste(char input[32]);
	friend istream & operator>>(istream&,materiale&);
    friend ostream & operator<<(ostream&,materiale&);

};

