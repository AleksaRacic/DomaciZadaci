#include "Datum.h"

int Datum::brojDanaUMesecu(int mes) const {
	switch (mes) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (this->godina % 400 == 0 || (this->godina % 4 == 0 && this->godina % 100 != 0))
			return 29;
		else
			return 28;
	default:
		return -1;
	}
}

void Datum::postaviDatum(int dan, int mes, int god) {
	//Ako nije validan datum postavlja na podrazumevani
	if ((mes >= 1 && mes <= 12) && (dan >= 1 && dan <= brojDanaUMesecu(mes))) {
		this->godina = god;
		this->mesec = mes;
		this->dan = dan;
	}
	else {
		postaviDatum(1, 1, 2021); //podrazumevani datum
	}
}

Datum::Datum(int d = 1, int m = 1, int g = 2021) {
	postaviDatum(d, m, g);
}

bool operator==(const Datum& d1, const Datum& d2) {
	return (d1.dan == d2.dan && d1.mesec == d2.mesec && d1.godina == d2.godina);

}

ostream& operator<<(ostream& os, const Datum& dat) {
	cout << dat.dan << '.' << dat.mesec << '.' << dat.godina << ".";
	return os;
}