#include "Osoba.h"

Osoba::Osoba(char* i, char *j, const Datum& d) :ime(i), JMBG(j), dat(d) {}; //Videti da li je osoba vlasnik datuma

ostream& operator<<(ostream& os, const Osoba& o) {
	cout << "O(" << o.get_ime() << ',' << o.get_JMBG() << ',' << o.get_dat() << ")";
	return os;
}