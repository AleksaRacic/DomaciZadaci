#include "Aranzman.h"
#include "Datum.h"
#include "Destinacija.h"
#include "Exceptions.h"
#include "Prevoz.h"
#include "Smestaj.h"

void main() {
	try {
		Destinacija dest1("Banjaluka", "Lep grad");
		cout << dest1 << endl;
		dest1.oceni(4);
		cout << dest1 << endl;
		dest1.oceni(5);
		cout << dest1 << endl;
		dest1.oceni(6);
		Destinacija dest2("Beograd", "nice");
		dest2.oceni(3);
		if (dest1 > dest2) cout << dest2 << endl;
		Smestaj s1(dest1, Smestaj::HOTEL, "Tre Cane", 4, 3000);
		cout << s1<<endl;
		Prevoz prev(dest2, 200);
		Datum dat1(3, 6, 2019);
		Datum dat2(4, 9, 2020);
		cout << dat1 - Datum(5, 7, 2020) << endl;
		cout << Datum(3, 6, 2020) - dat1 << endl;
		cout << dat1 << endl;
		Aranzman aranz(dest1, dat1, dat2);
		aranz.dodaj_smestaj(s1);
		aranz.dodaj_prevoz(prev);
		cout << aranz.cena() << endl;
		cout << aranz << endl;

		Aranzman aranz2(dest2, dat1, dat2);
		cout << aranz2.cena();
	}catch(GAra gr) {
		cout << gr.what()<<endl;
	}
	catch (GDatum gr) {
		cout << gr.what() << endl;
	}
	
}