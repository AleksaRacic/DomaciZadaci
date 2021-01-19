#include "Mec.h"


void main() {
	try {
		Igrac igrac("Nikola Zigic", 200);
		Igrac igrac2("C R");
		cout << igrac2 << endl;
		igrac2.promeni_procentualno(10);
		cout << igrac2 << endl;
		igrac2.promeni_procentualno(-10);
		cout << igrac2 << endl;
		Igrac igrac3("Dusko Tosic", 20);
		Tim tim1("RMA", 11);
		cout << tim1.get_br() << endl;
		tim1.add_player(igrac, 3);
		tim1.add_player(igrac2, 4);
		cout << tim1.get_br() << endl;
		cout << tim1 << endl;
		Igrac igrac4("Vidic", 500);

		Tim tim2("Bar", 11);
		tim2.add_player(igrac4, 5);
		tim2.add_player(igrac3, 4);
		Igrac *tmp = tim2[5];
		if (tmp != nullptr) cout << *tmp << endl;
		tmp = tim2[6];
		if (tmp != nullptr) cout << *tmp << endl;
		else cout << "Nema igraca\n";
		Privilegovani tim3("Ime", 11, 100);
		tim3.add_player(igrac4, 4);
		tim3.add_player(igrac, 6);

		Par<Tim> par1(&tim3, &tim2);
		cout << par1;



	}
	catch (exception gr) {
		cout << gr.what();
	}


}