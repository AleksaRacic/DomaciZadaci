#include "OOP_V2.h"

//Nutritivna_Vrednost

Nutritivna_Vrednost operator+(const Nutritivna_Vrednost& nut1, const Nutritivna_Vrednost& nut2) {
	return Nutritivna_Vrednost(nut1.get_uh() + nut2.get_uh(), nut1.get_ma() + nut2.get_ma(), nut1.get_pr() + nut2.get_pr());
}

ostream& operator<<(ostream& os, const Nutritivna_Vrednost& nut) {
	os << "[uh:  " << nut.get_uh() << ",  ma:  " << nut.get_ma() << ",  pr:  " << nut.get_pr() << "]";
	return os;
}

//Namirnica

bool operator== (const Namirnica& nam1, const Namirnica& nam2) {
	return nam1.get_naziv() == nam2.get_naziv();
}

ostream& operator<<(ostream& os, const Namirnica& nam) {
	os << nam.naziv << "-"<<nam.nut_vr;
	return os;
}
//Sastojak

Nutritivna_Vrednost Sastojak::nut_vr() const {
	double kol = gr / 100;
	return Nutritivna_Vrednost(namirnica.get_nut().get_uh()*kol, namirnica.get_nut().get_ma()*kol, namirnica.get_nut().get_pr()*kol);
}

double Sastojak::get_cal() const {
	return namirnica.get_nut().get_cal()*(gr / 100);

}

ostream& operator<<(ostream& os, const Sastojak& s) {
	os << "[" << s.get_cal() << " kcal] " << s.get_gr() << " g x " << s.get_nam().get_naziv();
	return os;
}

//Lista

template<typename T> void Lista<T>::brisi() {
	set_front();
	element* tmp;
	while (is_tek()) {
		tmp = tek;
		next();
		delete tmp;
	}
	prvi = poslednji = nullptr;
}

template<typename T> Lista<T>& Lista<T>::push_back(const T& t) {
	if (prvi==nullptr) { prvi = poslednji = new element(t); return *this; }

	poslednji->sled = new element(t);
	poslednji = poslednji->sled;
	return *this;
}

template<typename T> T& Lista<T>::get_elem() const {
	if (!is_tek()) throw(GTek());
	return tek->info;
}

template <typename T> Lista<T>::~Lista() { brisi(); }


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