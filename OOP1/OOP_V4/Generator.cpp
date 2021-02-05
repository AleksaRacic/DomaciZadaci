#include "Generator.h"

Izraz& Generator::operator()(Izraz& iz) {
	Izraz &kopija = *(iz.kopiraj());
	Izraz stek;
	Izraz* izlaz = new Izraz;
	while (kopija.get_br_pod()) {
		auto tmp = *kopija;
		if (tmp->get_oznaka() == 'D') {
			(*izlaz) += *tmp->kopiraj();
		}
		else if (tmp->get_oznaka() == 'O') {
			while (stek.get_br_pod()) {
				auto top = -stek;
				if ((top->get_oznaka() != '(') && !(*dynamic_cast<Binarni_Operator*>(tmp) > *dynamic_cast<Binarni_Operator*>(top))) {
					(*izlaz) += *top;
				}
				else {
					stek += *top;
					break;
				}
			}
			stek += *tmp;
		}
		else if (tmp->get_oznaka() == '(') {
			stek += *tmp->kopiraj(); //izbrisati kopiraj
		}
		else if (tmp->get_oznaka() == ')') {
			do {
				try {
					auto top = -stek;
					if (top->get_oznaka() == '(') break;
					(*izlaz) += *top;

				}
				catch (GPrazna ex) {
					throw(GPostfix()); //nema druge zagrade
				}
			} while (1);

		}
	}
	while (stek.get_br_pod()) {
		auto top = -stek;
		if (top->get_oznaka() == '(') throw(GPostfix());
		(*izlaz) += *top;

	}

	return *izlaz;
}