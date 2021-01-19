#include "Generator.h"

Izraz& Generator::operator()(Izraz& iz) {
	Izraz &kopija = *(iz.kopiraj());
	Izraz stek;
	Izraz* izlaz = new Izraz;
	while (kopija.get_br_pod()) {
		auto tmp = *kopija;
		if (tmp->get_oznaka() == 'D') {
			(*izlaz) += tmp->kopiraj();
		}
		else if (tmp->get_oznaka() == 'O') {
			while (stek.get_br_pod()) {
				auto top = -stek;
				if (top->get_oznaka() != '(' && top > tmp) {
					(*izlaz) += top;
				}
				else {
					stek += top;
					break;
				}
			}
			stek += tmp;
		}
		else if (tmp->get_oznaka() == '(') {
			stek += tmp->kopiraj();
		}
		else if (tmp->get_oznaka() == ')') {
			do {
				try {
					auto top = -stek;
					if (top->get_oznaka() == '(') break;
					(*izlaz) += top;

				}
				catch (GPrazna ex) {
					throw(GPostfix()); //nema druge zagrade
				}
			} while (1);

		}
		cout << "Stek "<< stek <<endl;
		cout << "Izlaz " << *izlaz << endl;
	}
	while (stek.get_br_pod()) {
		auto top = -stek;
		if (top->get_oznaka() == '(') throw(GPostfix());
		(*izlaz) += top;

	}

	return *izlaz;
}