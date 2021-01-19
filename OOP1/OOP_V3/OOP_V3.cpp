#include "Mec.h"

using namespace std;

bool operator==(const Igrac& igrac1, const Igrac& igrac2) {
	return (igrac1.get_ime() == igrac2.get_ime() && igrac1.get_vr() == igrac2.get_vr());
}

ostream& operator<<(ostream& os, const Igrac& ig) {
	os << ig.get_ime() << "#" << ig.get_vr();
	return os;
}

//Tim

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
		if(t.niz[i]!=nullptr) niz[i] = new Igrac(*(t.niz[i]));
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

Igrac* Tim::operator[](int i){
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

//Privilegovani

void Privilegovani::add_player(Igrac& ig, int i) {
	if (ig.get_vr() < min_vr) throw(errPrik());
	else Tim::add_player(ig, i);
}

ostream& Privilegovani::print(ostream& os) const {
	Tim::print(os) << "(" << min_vr << ")";
	return os;
}

//Par



//Mec

Mec::Mec(Tim& domacin, Tim& gost) : odigran(false) {
	par = new Par<Tim>(&domacin, &gost);
}

void Mec::odigraj() {
	int sr1 = par->get_prvi()->sr_vr();
	int sr2 = par->get_drugi()->sr_vr();

	if (sr1 > sr2) {
		ishod = POBEDA_DOMACIN;
		par->get_prvi()->promeni_procentualno(10);
		par->get_drugi()->promeni_procentualno(-10);

	}
	else if (sr2 == sr1) {
		ishod = NERESENO;
	}
	else {
		ishod = POBEDA_GOST;
		par->get_prvi()->promeni_procentualno(-10);
		par->get_drugi()->promeni_procentualno(10);
	}
	odigran = true;
}

Par<int> Mec::rezultat() const {
	//videti kako ovo da se resi, da li dodati novo polje unutar klase
	int* prvi = new int;
	int* drugi = new int;
	if (!odigran) throw(errMec());
	switch (ishod) {
	case POBEDA_DOMACIN:
		*prvi = 3;
		*drugi = 0;
		break;
	case NERESENO:
		*prvi = 3;
		*drugi = 0;
		break;
	case POBEDA_GOST:
		*prvi = 0;
		*drugi = 3;
		break;
	}
	return Par<int>(prvi, drugi);
}
