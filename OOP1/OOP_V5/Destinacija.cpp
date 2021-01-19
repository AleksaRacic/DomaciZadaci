#include "Destinacija.h"

void Destinacija::oceni(unsigned int ocena) {
	if (ocena <= 5) {
		this->pr = ((pr * br_oc) + (double)ocena) / (br_oc+1);
		br_oc++;
	}
}

bool operator>(const Destinacija& d1, const Destinacija& d2) {
	return d1.get_pr() > d2.get_pr();
}


ostream& operator<<(ostream& os, const Destinacija& d) {
	os << "[" << d.get_pr() << "] " << d.get_naziv() << " (" << d.get_opis() << ")";
	return os;
}