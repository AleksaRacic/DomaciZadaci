#include "Mec.h"

Mec::Mec(Par<Tim> pa) : odigran(false), par(pa) {}

void Mec::odigraj() {
	int sr1 = par.get_prvi()->sr_vr();
	int sr2 = par.get_drugi()->sr_vr();

	if (sr1 > sr2) {
		ishod = POBEDA_DOMACIN;
		par.get_prvi()->promeni_procentualno(10);
		par.get_drugi()->promeni_procentualno(-10);

	}
	else if (sr2 == sr1) {
		ishod = NERESENO;
	}
	else {
		ishod = POBEDA_GOST;
		par.get_prvi()->promeni_procentualno(-10);
		par.get_drugi()->promeni_procentualno(10);
	}
	odigran = true;
}

Par<int> Mec::rezultat() const {
	//videti kako ovo da se resi, da li dodati novo polje unutar klase
	prvi = new int;
	drugi = new int;
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