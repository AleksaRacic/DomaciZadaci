#include "Aranzman.h"


void Aranzman::dodaj_smestaj(Smestaj &s) {
	if (s.get_dest().get_naziv() != dest.get_naziv()) throw(GAra("Greska u dodavanju smestaja")); //Ovo sam uradio kao poredjenje adresa, pitati da li treba porediti po nazivu
	smestaj = &s;
}

void Aranzman::dodaj_prevoz(Prevoz &s) {
	if (s.get_dest().get_naziv() != dest.get_naziv()) throw(GAra("Greska u dodavanju smestaja")); //Ovo sam uradio kao poredjenje adresa, pitati da li treba porediti po nazivu
	prevoz = &s;
}

//Testirati ovo

double Aranzman::cena()const {
	if (!(smestaj && prevoz)) { throw(GAra("Nisu dodeljeni prevoz i smestaj")); }
	return smestaj->get_cena()*trajanje() + prevoz->get_cena();
}

ostream& operator<<(ostream& os, const Aranzman& ar) {
	os << ar.get_dest() << endl;
	if (ar.smestaj) os << ar.smestaj << endl;
	else throw(GAra("Nije dodeljen smestaj"));
	os << ar.cena();

}
