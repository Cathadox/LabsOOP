// MojTermin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;
class Lekar
{

private:
	int faksimil;
	char ime[10];
	char prezime[11];
	double oplata;
	void copy(const Lekar &l)
	{
		this->faksimil = l.faksimil;
		strcpy(this->ime, l.ime);
		strcpy(this->prezime, l.prezime);
		this->oplata = l.oplata;
	}
public:
	Lekar() {}
	Lekar(int faksimil, char* ime, char* prezime, double oplata)
	{
		this->faksimil = faksimil;
		strcpy(this->ime, ime);
		strcpy(this->prezime, prezime);
		this->oplata = oplata;
	}
	Lekar(const Lekar &l)
	{
		copy(l);
	}
	Lekar &operator=(const Lekar &l)
	{
		if (this != &l)
		{
			copy(l);
		}
		return *this;
	}
	~Lekar() {}
	void pecati()
	{
		cout << faksimil << ": " << ime << " " << prezime << endl;
	}
	virtual double plata()
	{
		return oplata;
	}
};
class MaticenLekar : public Lekar
{
private:
	int broj;
	double* kotizacii;
	void copy(const MaticenLekar &m)
	{
		this->broj = m.broj;
		this->kotizacii = new double[m.broj];
		for (int i = 0; i < broj; i++)
			this->kotizacii[i] = m.kotizacii[i];
	}
public:
	MaticenLekar() { kotizacii = new double[0]; }
	MaticenLekar(Lekar l, int broj, double* kotizacii) : Lekar(l)
	{
		this->broj = broj;
		this->kotizacii = new double[broj];
		for (int i = 0; i < broj; i++)
			this->kotizacii[i] = kotizacii[i];
	}
	MaticenLekar(const MaticenLekar &l) : Lekar(l)
	{
		copy(l);
	}
	MaticenLekar &operator=(const MaticenLekar &l)
	{
		Lekar::operator=(l);
		if (this != &l)
		{
			delete[]kotizacii;
			copy(l);
		}
		return *this;
	}
	void pecati()
	{
		Lekar::pecati();
		double average =0;
		for (int i = 0; i < broj; i++)
			average += kotizacii[i];
		cout <<"Prosek na kotizacii: "<< average / broj << endl;
	}
	double plata()
	{
		double average =0;
		for (int i = 0; i < broj; i++)
			average += kotizacii[i];
		return Lekar::plata() + 0.3*(average / broj);
	}
	~MaticenLekar() { delete[]kotizacii; }

};
int main()
{
	int n;
	cin >> n;
	int pacienti;
	double kotizacii[100];
	int faksimil;
	char ime[20];
	char prezime[20];
	double osnovnaPlata;

	Lekar * lekari = new Lekar[n];
	MaticenLekar * maticni = new MaticenLekar[n];

	for (int i = 0; i<n; i++) {
		cin >> faksimil >> ime >> prezime >> osnovnaPlata;
		lekari[i] = Lekar(faksimil, ime, prezime, osnovnaPlata);
	}

	for (int i = 0; i<n; i++) {
		cin >> pacienti;
		for (int j = 0; j<pacienti; j++) {
			cin >> kotizacii[j];
		}
		maticni[i] = MaticenLekar(lekari[i], pacienti, kotizacii);
	}

	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cout << "===TESTIRANJE NA KLASATA LEKAR===" << endl;
		for (int i = 0; i<n; i++) {
			lekari[i].pecati();
			cout << "Osnovnata plata na gorenavedeniot lekar e: " << lekari[i].plata() << endl;
		}
	}
	else {
		cout << "===TESTIRANJE NA KLASATA MATICENLEKAR===" << endl;
		for (int i = 0; i<n; i++) {
			maticni[i].pecati();
			cout << "Platata na gorenavedeniot maticen lekar e: " << maticni[i].plata() << endl;
		}
	}

	delete[] lekari;
	delete[] maticni;
	system("pause");
	return 0;
	system("pause");
}

