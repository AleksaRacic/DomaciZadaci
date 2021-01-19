#include "Smestaj.h"
#include <iostream>

Smestaj::Smestaj(Destinacija& d, Tip t, string n, int br, double c) :dest(d), tip(t), naziv(n), cena(c) {
	//videti da li je ovo dobro;
	if (br < 1 || br>5) throw(GOpseg());
	br_zv = br;
};

ostream& operator<<(ostream& os, const Smestaj& s) {
	if (s.get_tip() == Smestaj::HOTEL) {
		os << "HOTEL ";
	}
	else {
		os << "APARTMAN";
	}
	os << s.get_naziv();
	for (int i = 0; i < s.br_zv; ++i) os << "*";

	return os;
}