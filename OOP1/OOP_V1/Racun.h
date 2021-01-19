#ifndef Racun_H
#define Racun_H

#include "Osoba.h"

class Racun {
private:
	const Osoba& o;
	char* brojRac;
	int iznos = 0;
public:
	Racun(const Osoba& os, char* bRac) : o(os), brojRac(bRac) {};

	Racun(const Racun&) = delete;
	Racun& operator=(const Racun&) = delete;

	const Osoba& get_osoba()const { return o; }
	const char* get_brojRac() const { return brojRac; }
	const int& get_iznos()const { return iznos; }

	//Proveriti da li racun moze biti apstraktna klasa-----------
	virtual const char* get_val() const = 0;

	void uplati(Racun&, int);
	Racun& operator+=(int);
	friend ostream& operator<<(ostream&, const Racun&);
};

#endif