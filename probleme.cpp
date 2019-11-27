#include "probleme.h"
#include <cstdlib>
#inclide <cstring>
#include "atelier.h"
using namespace std;

istream & operator>>(istream& in,probleme& z)
{
    in>>z.name>>z.flags>>z.oo;
    return in;
}
ostream & operator<<(ostream& out,probleme& z)
{
    out<<z.name<<z.flags<<z.oo;
    return out;
}

probleme::probleme(char nume[256], char flg[64], int oo, char mat[256])
{
	strcpy(name, nume);
	strcpy(flags, flg);
	ore_om = oo;
	getMat(mat);
};
probleme::probleme() {

}

probleme::~probleme() {

};

void probleme::getMat(char src[256]) {
	int n = strnlen(src,256),z=0,v=0,last;
	char aux[32];
	ob *ax;
	for (int i=0; i<n; i++)
	{
		if (src[i] != ':')
		{
			aux[z] = src[i];
			z++;
		}
		else
		{
			aux[z] = '\0';
			z = 0;
			last = i;
			v = 0;
			if (src[i+1] == 'r') {
				i+=2;
				while (i <= n && src[i] != ';')
				{
					v = v*(i-last)+src[i]-'0';
					i++;
				}
				v = rand()%v+1;
			}
			else
			{
				while (src[i] != ';' || src[i] == '\0')
				{
					v = v*10+src[i]-'0';
					i++;
				}
			}
			ax = new  ob(materiale::gaseste(aux), v);
			listtt.adauga(ax);

		}
	}
};


void probleme::print()
{
	if (oo != 0) {
		cout<<"Problema: "<<name;
        cout<<" ore de lucru: "<<oo;
		cout<<" materiale necesare: ";
		lista<ob> *iter = &listtt;
		while (iter)
        {
			cout<<"Material: "<<iter->ths->mat->name;
			cout<<iter->ths->mat->cost<<" lei/buc";
			cout<<"buc: "<<iter->ths->count;
			cout<<"pret total: "<<iter->ths->count*iter->ths->mat->cost;
			atelier::cost_final += iter->ths->count*iter->ths->mat->cost;
			atelier::cost_final += atelier::ore_om * oo;
			iter = iter->next;
		};
		cout<<endl;
	}
	else
	{
		cout<<"Problema capitala";
	}
};

bool probleme::tag(const char z)
{
	if (strchr(flags, z))
	{
		return true;
	}
	return false;
}
