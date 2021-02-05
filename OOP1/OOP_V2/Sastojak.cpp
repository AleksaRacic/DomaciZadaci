#include "Sastojak.h"

Nutritivna_Vrednost Sastojak::nut_vr() const {
	double kol = gr / 100;
	return Nutritivna_Vrednost(namirnica.get_nut().get_uh()*kol, namirnica.get_nut().get_ma()*kol, namirnica.get_nut().get_pr()*kol);
}

double Sastojak::get_cal() const {
	return namirnica.get_nut().get_cal()*(gr / 100);

}

ostream& operator<<(ostream& os, const Sastojak& s) {
	os << "[" << s.get_cal() << " kcal] " << s.get_gr() << " g x " << s.get_nam().get_naziv();
	return os;
}