#include "Datum.h"
#include "Dinarski_Racun.h"
#include "Racun.h"
#include "Exceptions.h"

void main() {
	try {
		Datum dat(3, 4, 2000);
		Datum dat1(32, 2, 2001);
		Datum dat2(3, 4, 2000);
		if (dat == dat2) cout << "Jednaki\n";
		else cout << "Nisu jednaki\n";
		if (dat1 == dat2) cout << "Jednaki\n";
		else cout << "Nisu jednaki\n";
		cout << dat1 << endl;
		Osoba osoba1("Aleksa R", "2523434", dat1);
		Osoba osoba2("Marko Nikol", "2342342", Datum(1, 1, 2000));
		cout << osoba2 << endl;
		//Osoba osoba3 = Osoba("Neko", "235345", dat); nema premestanja
		//Osoba osoba4 = osoba3; nema kopiranja

		Dinarski_Racun rac1(osoba1, "230023023");
		cout << rac1 << endl;
		rac1 += 1000;
		cout << rac1 << endl;
		Dinarski_Racun rac2(osoba2, "3293203");
		rac1.uplati(rac2, 100);
		cout << rac2 << endl;
		rac2.uplati(rac1, 200);

	}
	catch (errRac r) {
		cout << r.what() << endl;
	}
}