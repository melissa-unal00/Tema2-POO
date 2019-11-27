#include <iostream>
#include <cstdlib>
#inclide <cstring>
using namespace std;

template<class T>
class lista
{
private:
//	static int id_seed;
//	int id;

public:
	lista<T> *next = nullptr;
	static lista<T> *first, *last;
	T *ths = nullptr;
	lista();
	~lista();
	void add(T *obiect);
	void close();
	void foreach(void(*f) (T));
	T *obiect();
	T *get1(int n);
	T *get2(int n, char z[1]);
};

