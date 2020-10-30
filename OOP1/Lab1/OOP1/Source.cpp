#include <string>
#include <iostream>
#include <list> 

using namespace std;
class Pilot {
private:
	string ime;
	int sati_letenja;
	bool leti = false;

	//proveriti razliku izmedju ovoga i 
	//Pilot(const Pilot& p); ovo daje samo jednu kopiju
public:
	Pilot(const Pilot& p) = delete;

	Pilot() {
	}

	Pilot(string ime, int sati_letenja, bool leti) {
		this->ime = ime;
		this->sati_letenja = sati_letenja;
		this->leti = leti;

	}

	string getName() {
		return ime;
	}

	int getHours() {
		return sati_letenja;
	}
	
	bool isAirborne() {
		return leti;
	}

	void setHours(int hours) {
		this->sati_letenja = hours;
	}
	void incHours(int hours) {
		sati_letenja += hours;
	}

	void setAirborne(bool airborne) {
		leti = airborne;
	}

	void status() {
		cout << ime << "(" << sati_letenja << ")-" << isAirborne() ? 'L' : 'N' << '\n';
	}
};

class Avion {
public:
	Avion();
	string name;
	Pilot* pilot = nullptr;
	Pilot* copilot = nullptr;
	int max_passengers;
	Avion(const Avion& a) = delete;
	Avion(string name, int max_passengers) {
		this->name = name;
		this->max_passengers = max_passengers;

	}
	~Avion() {
		if (pilot) {
			pilot->setAirborne(false);
		}
		if (copilot) {
			copilot->setAirborne(false);
		}
	}
	void setPilot(Pilot &p) {
		if (p.getHours() < 100) {
			cout << "ne moze se postaviti \n";
		}
		else {
			pilot = &p;
			pilot->setAirborne(true);
		}
	}

	void setCopilot(Pilot &p) {
		copilot = &p;
		copilot->setAirborne(true);
	}

	void ispis() {
		cout << "AVION:" << name << "-" << max_passengers<<endl;
	}

};

bool uslovIzbacivanja(const Avion* a, string ime) {
	if (a->name == ime) {
		return 1;
	}else{
		return 0;
	}
}

class Flota {
private:
	string name;
	list<Avion*> l;
public:
	Flota(string name) {
		this->name = name;
	}
	void addPlane(Avion& a) {
		l.push_front(&a);
	}


	int numOfPlanes() {
		return l.size();
	}
	int numOfPass() {
		int broj = 0;
		for (Avion* a : l) {
			broj += a->max_passengers;
		}
		return broj;
	}

	Avion* maxPutnika() {
		Avion* tmp=nullptr;
		int broj = 0;
		for (Avion* a : l) {
			if (a->max_passengers > broj) {
				broj = a->max_passengers;
				tmp = a;
			}
			
		}
		return tmp;
	}

	void ispis() {
		cout << name << endl;
		for (Avion* a : l) {
			a->ispis();
		}
	}
	void eject(string ime) {
		for (auto it = l.begin(); it != l.end();) {
			if ((*it)->name == ime) {
				it = l.erase(it);
			}
			else {
				++it;
			}
		}
	}
	void findBetween(int min, int max) {
		for (Avion* a : l) {
			if (a->max_passengers > min && a->max_passengers < max) {
				a->ispis();
			}
		}
	}
};

class Let {
private:
	string polaziste;
	string odrediste;
	static int id;
	int id1;
	Avion* avion;
public:
	Let(string polaziste, string odrediste, Avion& avion) {
		this->polaziste = polaziste;
		this->odrediste = odrediste;
		this->avion = &avion;
		id++;
		id1 = id;
	}

	string getPolaziste() { return polaziste; }
	string getOdrediste() { return odrediste; }
	void ispisi() {
		cout << "LET-" << polaziste << ":" << odrediste << "-" << avion->name << endl;
	}

};

int Let::id = 0;

class Arhiva {
private:
	list <Let*> arhiva1;
public:
	Arhiva() {}
	~Arhiva() {
		cout << "Objekat arhive izbrisan";
	}
	void dodajLet(Let& let) {
		arhiva1.push_front(&let);
	}
	list <Let*> getOdredista(string odrediste) {
		list <Let*> l;
		for (Let* let : arhiva1) {
			if (let->getOdrediste() == odrediste) {
				l.push_front(let);
			}
		}
		return l;
	}

	list <Let*> getPolaziste(string polaziste) {
		list <Let*> l;
		for (Let* let : arhiva1) {
			if (let->getPolaziste() == polaziste) {
				l.push_front(let);
			}
		}
		return l;
	}

	list <Let*> getPolOdr(string polaziste, string odrediste) {
		list <Let*> l;
		for (Let* let : arhiva1) {
			if (let->getOdrediste() == odrediste && let->getPolaziste() == polaziste) {
				l.push_front(let);
			}
		}
		return l;
	}

	void ispis() {
		cout << "ARHIVA" << endl;

		for (Let* let : arhiva1) {
			let->ispisi();
		}
	}
};



int main() {
	Arhiva obj;
	Pilot p1("MArko", 110, 0);
	Pilot p2("Nikola", 70, 0);
	Pilot p3("Savo", 120, 0);
	Pilot p4("Dejan", 80, 0);
	Avion a1("Airbus", 50);
	Avion a2("Boing", 60);
	p3.status();
	a1.setPilot(p2);
	a1.setPilot(p1);
	a1.setCopilot(p2);
	Flota flota("flotica");
	flota.addPlane(a1);
	a2.setPilot(p3);
	a2.setCopilot(p4);
	p3.status();
	a2.ispis();
	flota.ispis();
	flota.addPlane(a2);
	flota.ispis();
	p1.setHours(130);
	flota.maxPutnika()->ispis();
	cout << flota.numOfPass();
	flota.eject("Airbus");
	flota.ispis();
	Let l1("Beograd", "Subotica", a1);
	obj.dodajLet(l1);

	Let l2("Subotica", "Budimpesta", a2);
	obj.dodajLet(l2);

	l1.ispisi();
	obj.ispis();
	list <Let*> l = obj.getOdredista("Subotica");
	cout << "Filtrirani letovi" << endl;
	for (Let* a : l) a->ispisi();
	return 0;
}