#include "lista.h"
#include "probleme.h"
#include <iostream>
#include <cstdlib>
#inclide <cstring>
using namespace std;

template<class T>
lista<T> *lista<T>::first;
template<class T>
lista<T> *lista<T>::last = first;

//Constructor implicit
template<class T>
lista<T>::lista()
{};

//Destructor ce ajuta la deinitializarea corespunzatoare a listelor
template<class T>
lista<T>::~lista()
{
	lista<T> *iter = first;
	lista<T> *lst;
	if (iter)
    {
		do
		{
			lst = iter;
			iter = iter->next;
			delete(lst);
		}
        while (iter->next);
	}
	delete(iter);
};

//Adauga un nou elem de tipul template-ului la o lista existenta/nou creata
template<class T>
void lista<T>::add(T *obiect)
{
	lista<T> *iter = this;
	if (iter->ths)
	{
		while (iter->next)
		{
			iter = iter->next;
		}
		iter->next = new lista < T >;
		iter->next->ths = obiect;
		iter->next->next = nullptr;
	}
	else
	{
		iter->ths = obiect;
	}
};


//Inchide lista legand ultimul element de primul
template<class T>
void lista<T>::close()
{
	last->next = first;
};

/*Aplica o functie f ce returneaza void si primeste un parametru
de tipul template-ului fiecarui element din lista unui tip
(2 liste declarate separat dar care au acelasi tip de continut vor fi "concatenate")*/

template<class T>
void lista<T>::foreach(void(*f)(T))
{
	lista<T> *iter = first;
	do {
		f(*iter->ths);
		if (iter->next)
		{
			iter = iter->next;
		}
		else
		{
			iter = first;
		}
	} while (iter != first);
};


template<class T>
T *lista<T>::obiect() {
	return ths;
}

template<class T>
T *lista<T>::get1(int n) {
	lista<T> *frst = this;
	lista<T> *iter = frst;
	int i = 1;
	while (i < n)
	{
		if (iter->next)
		{
			iter=iter->next;
		}
		else
		{
			iter = frst;
		}i++;
	}
	return iter->obiect();
};

template class lista<probleme>;
template class lista<materiale>;
template class lista<ob>;
