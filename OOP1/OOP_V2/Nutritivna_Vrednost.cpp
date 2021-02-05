#include "Nutritivna_Vrednost.h"

Nutritivna_Vrednost operator+(const Nutritivna_Vrednost& nut1, const Nutritivna_Vrednost& nut2) {
	return Nutritivna_Vrednost(nut1.get_uh() + nut2.get_uh(), nut1.get_ma() + nut2.get_ma(), nut1.get_pr() + nut2.get_pr());
}

ostream& operator<<(ostream& os, const Nutritivna_Vrednost& nut) {
	os << "[uh:  " << nut.get_uh() << ",  ma:  " << nut.get_ma() << ",  pr:  " << nut.get_pr() << "]";
	return os;
}
