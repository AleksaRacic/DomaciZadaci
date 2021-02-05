#include "Racun.h"
#include "Exceptions.h"

void Racun::uplati(Racun& rac2, int iznos) {
	if (this->get_iznos() < iznos) throw errRac();

	this->iznos -= iznos;
	rac2 += iznos;
}

Racun& Racun::operator+=(int iz) {
	iznos += iz;
	return *this;
}

ostream& operator<<(ostream& os, const Racun& rac) {
	cout << rac.get_brojRac() << ":=:" << rac.get_iznos() << rac.get_val();
	return os;
}