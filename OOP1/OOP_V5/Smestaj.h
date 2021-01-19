#pragma once

#include "Destinacija.h"
#include "Exceptions.h"

class Smestaj {
public:
	enum Tip { HOTEL, APARTMAN };
private:
	Destinacija& dest;
	string naziv;
	Tip tip;
	int br_zv;
	double cena;
public:

	Smestaj(Destinacija&, Tip, string, int, double);
	Tip get_tip() const { return tip; };
	const Destinacija& get_dest() const { return dest; }
	const string& get_naziv() const { return naziv; }
	int get_br_zv() const { return br_zv; }
	double get_cena() const { return cena; }
	friend ostream& operator<<(ostream&, const Smestaj&);
};