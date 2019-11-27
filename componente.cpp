#include <conio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "componente.h"
using namespace std;

template class componente<frane>;
template class componente<motor>;
template class componente<caroserie>;
template class componente<directie>;
template class componente<emisii>;


template<typename T>
lista<probleme> componente<T>::prob;

template<class T>
void componente<T>::adauga(char nume[256], char flg[64], int mnhrs, char materials[256]){
	probleme aux(nume, flg, mnhrs, materials);
	this->prob.adauga(&aux);
};

template<class T>
void componente<T>::damage(char flag)
{
	int i = rand() % 10+1;
	if (i>3)
        {
            i = rand() % 20 + 1;
            probleme *aux = nullptr;
                if (tag_valid(flag))
                    {
                        aux = get_tag(i, flag);
                    }
                if(aux)
                    {
                        actualProblems.adauga(aux);
                    }
        }
};

template<class T>
bool componente<T>::tag_valid(char flag)
{
	lista<probleme> *iter = &this->prob;
	while (iter)
	{
		if (iter->obiect()->hasTag(flag))
		{
			return true;
		}
		iter = iter->next;
	}
	return false;
};

template<class T>
probleme *componente<T>::get_tag(int n, char z)
{
	lista<probleme> *frst = &this->prob;
	lista<probleme> *iter = &this->prob;
	int ok = 0;
	int i = 1;
	while (i < n)
	{
		if (iter->next)
		{
			ok = 0;
			while (!ok)
			{
				if (iter->obiect()->hasTag(z))
				{
					ok = 1;
				}
				else
				{
					if (iter->next)
					{
						iter = iter->next;
					}
					else
					{
							iter = frst;
					}
				}
			}
			i++;
		}
		else
		{
			i = n;
		}
	}
	return iter->obiect();
};

template<class T>
void componente<T>::diagnostic()
{
	if(actualProblems.obiect())
	{
		actualProblems.obiect()->print();
	}
};

//adaugarea problemelor ce va fi apelata in main
template<class T>
void componente<T>::adauga_probleme(char nume[256], char flg[64], int mnhrs, char materials[256] = "\n")
{
	probleme *aux = new probleme(nume, flg, mnhrs, materials);
	componente::prob.adauga(aux);
}
