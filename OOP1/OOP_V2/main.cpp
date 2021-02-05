#include "Sastojak.h"
#include "Exceptions.h"
#include "Lista.h"
#include "Nutritivna_Vrednost.h"
#include "Namirnica.h"
void main() {
	try {
		Nutritivna_Vrednost nut1(2.5, 3.8, 2.9);
		const Nutritivna_Vrednost nut2(1, 1, 1);
		Nutritivna_Vrednost nut3 = nut1 + nut2;
		cout << nut1 << endl << nut3;
		cout << nut2.get_cal();
		Namirnica nam1("Banana", nut1, false);
		Namirnica nam2("Banana", nut3, false);
		Namirnica nam3("Kivi", nut2, true);
		if (nam1 == nam2)cout << "Jednake\n";
		cout << nam1 << endl;
		cout << nam2 << endl;
		Sastojak s1(nam1, 100);
		Sastojak s2(nam3, 50);
		Sastojak s3(nam2, 30);
		cout << s1.nut_vr() << endl;
		cout << s2.get_cal() << endl;
		Lista<Sastojak> l1;
		l1.push_back(s1);
		l1.push_back(s2).push_back(s3);
		l1.set_front();
		cout << l1.get_elem() << endl;
		l1.next();
		cout << l1.get_elem() << endl;
		l1.isprazni();
		l1.get_elem();
	}
	catch (GTek g) {
		cout << g.what() << endl;
	}

}