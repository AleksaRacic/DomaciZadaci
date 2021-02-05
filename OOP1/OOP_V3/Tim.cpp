#include "Tim.h"

Tim::Tim(const string& s, int m) : naziv(s), max_br(m), tr_br(0) { // da li ovako ili u definiciji staviti = 0
	niz = new Igrac*[max_br]();
}

void Tim::add_player(Igrac& ig, int i) {
	if (i < max_br&&i>1) {
		if (niz[i] != nullptr) {
			delete niz[i];
			--tr_br;
		}
		niz[i] = new Igrac(ig);
		++tr_br;
	}

}

void Tim::premesti(Tim& t) {
	naziv = t.naziv;
	tr_br = t.tr_br;
	max_br = t.max_br;
	niz = t.niz;
	t.niz = nullptr;
}

void Tim::kopiraj(const Tim& t) {
	naziv = t.naziv;
	tr_br = t.tr_br;
	niz = new Igrac*[max_br = t.max_br]();
	for (int i = 0; i < max_br; i++) {
		if (t.niz[i] != nullptr) niz[i] = new Igrac(*(t.niz[i]));
		//Rekli su da lista sadrzi kopije igraca, a ne reference
	}
}

void Tim::brisi() {
	if (niz) {
		for (int i = 0; i < max_br; i++) {
			delete niz[i];
		}
		delete[] niz;
		niz = nullptr;
	}
}


Igrac* const Tim::operator[](int i) const {
	if (i < 0 || i > max_br - 1) return nullptr;
	return const_cast<Igrac* const>(niz[i]);
}

Igrac* Tim::operator[](int i) {
	if (i < 0 || i > max_br - 1) return nullptr;
	return niz[i];
}

int Tim::sr_vr() {
	int total = 0;
	for (int i = 0; i < max_br; i++) {
		if (niz[i]) total += niz[i]->get_vr();
	}
	return total / tr_br;
}

bool operator==(const Tim& t1, const Tim& t2) {
	if (t1.naziv != t2.naziv) return false;
	if (t1.max_br != t2.max_br) return false;
	for (int i = 0; i < t1.max_br; ++i) {
		if (!(*t1[i] == *t2[i])) return false;
	}
	return true;
}

ostream& Tim::print(ostream & os) const {
	os << naziv << "[";
	for (int i = 0; i <max_br; i++) {
		if (this->operator[](i)) os << *(this->operator[](i)) << ", ";
	}
	os << "\b\b]";
	return os;
}

void Tim::promeni_procentualno(int pr) {
	for (int i = 0; i < max_br; i++) {
		if (this->operator[](i)) this->operator[](i)->promeni_procentualno(pr);
	}
}
