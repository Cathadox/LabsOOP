// KvadratiPravoagolnik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
using namespace std;
class Kvadrat {
protected:
	//TODO da se deklariraat promenlivite
	double a;
public:
	//TODO default konstruktor
	Kvadrat() {}
	//TODO konstruktor so argumenti
	Kvadrat(double a)
	{
		this->a = a;
	}
	//TODO copy konstruktor
	Kvadrat(const Kvadrat &k)
	{
		this->a = k.a;
	}
	//TODO double perimentar() {}
	virtual double perimetar()
	{
		return 4 * a;
	}
	//TODO double plostina() {}
	virtual double plostina()
	{
		return a*a;
	}
	//TODO void pecati();
	virtual void pecati()
	{
		cout << "Kvadrat so dolzina a=" << a << " ima plostina P=" << plostina() << " i perimetar L=" << perimetar() << endl;
	}
};

class Pravoagolnik : public Kvadrat { //da se vmetni nasleduvanjeto
private:
	//deklariranje na promenlivite
	double x;
	double y;
public:
	//TODO default konstruktor
	Pravoagolnik() {}
	//TODO konstruktor 
	Pravoagolnik(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	Pravoagolnik(const Kvadrat &k, double x, double y) : Kvadrat(k)
	{
		this->x = x;
		this->y = y;
	}
	
	//TODO copy konstruktor
	Pravoagolnik(const Pravoagolnik &p) : Kvadrat(p)
	{
		this->x = p.x;
		this->y = p.y;
	}
	//TODO prepokrivanje na metodite perimetar, plostina i pecati od klasata Kvadrat
	double perimetar()
	{
		return 2 * (a + x) + 2 * (a + y);
	}
	double plostina()
	{
		return (a + x)*(a + y);
	}
	void pecati()
	{
		if (x == y)
		{ 
			Kvadrat p(a + x);
			p.pecati();
		}
		else
			cout << "Pravoagolnik so strani:"<< a+x <<" i b="<<a+y<< " ima plostina P=" << plostina() << " i perimetar L=" << perimetar() << endl;
	}
};
int main()
{
	int n;
	double a, x, y;
	Kvadrat * kvadrati;
	Pravoagolnik * pravoagolnici;

	cin >> n;

	kvadrati = new Kvadrat[n];
	pravoagolnici = new Pravoagolnik[n];

	for (int i = 0; i<n; i++) {
		cin >> a;

		kvadrati[i] = Kvadrat(a);
	}

	for (int i = 0; i<n; i++) {
		cin >> x >> y;

		pravoagolnici[i] = Pravoagolnik(kvadrati[i], x, y);
	}

	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cout << "===Testiranje na klasata Kvadrat===" << endl;
		for (int i = 0; i<n; i++)
			kvadrati[i].pecati();
	}
	else {
		cout << "===Testiranje na klasata Pravoagolnik===" << endl;
		for (int i = 0; i<n; i++)
			pravoagolnici[i].pecati();
	}
	system("pause");
}

