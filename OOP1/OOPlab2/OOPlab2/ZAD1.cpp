#include <iostream>

using namespace std;
typedef unsigned short int usi;

class Piksel {
private:
	usi R, G, B;
public:
	Piksel();
	Piksel(usi,usi,usi);
	//~Piksel(); default destruktor je dovoljan
	usi getR() const { return R; }
	usi getG() const { return G; }
	usi getB() const { return B; }
	Piksel operator+(const Piksel&) const;
	friend bool operator==(const Piksel&, const Piksel&);
	friend ostream& operator<<(ostream&, const Piksel&);
};


Piksel::Piksel(usi R, usi G, usi B) {
	this->R = R;
	this->G = G;
	this->B = B;

}
Piksel::Piksel() {
	R = G = B = 0;
}

Piksel Piksel::operator+(const Piksel& rPiksel) const {
	Piksel piksel((this->getR() + rPiksel.getR()) / 2, (this->getG() + rPiksel.getG()) / 2, (this->getB() + rPiksel.getB()) / 2);
	return piksel;
}

bool operator==(const Piksel& rPiksel, const Piksel& lPiksel) {
	return rPiksel.R == lPiksel.R && rPiksel.R == lPiksel.R && rPiksel.R == lPiksel.R;
}

ostream& operator<<(ostream& os, const Piksel& piksel) {
	cout << "(" << piksel.getR() << ", " << piksel.getG() << ", " << piksel.getB() << ")\n";
	return os;
}


class Pozicija {
private:
	unsigned int x, y;
public:
	unsigned int getX() const { return x; }
	unsigned int getY() const { return y; }
	Pozicija(unsigned int, unsigned int);
};

Pozicija::Pozicija(unsigned int x, unsigned y) {
	this->x = x;
	this->y = y;
}

int operator+(const Pozicija& lPozicija, const Pozicija& rPozicija) {
	unsigned int ras_kol = lPozicija.getX() > rPozicija.getX() ? lPozicija.getX() - rPozicija.getX() : lPozicija.getX() - rPozicija.getX();
	unsigned int ras_vr = lPozicija.getY() > rPozicija.getY() ? lPozicija.getY() - rPozicija.getY() : lPozicija.getY() - rPozicija.getY();
	return ras_kol + ras_vr;
}

class Slika {
private:
	unsigned int height, width;
	Piksel **slika;
	friend class Crno_Bela_Slika;
public:
	Slika();
	Slika(unsigned int, unsigned int);
	~Slika();
	Slika(const Slika&);
	Slika(Slika&&);
	const Piksel operator[](const Pozicija&)const;
	virtual void setPiksel(const Piksel&, const Pozicija&);
	unsigned long int size()const;
	friend ostream& operator<<(ostream&, const Slika&);
};

Slika::Slika(unsigned int height, unsigned int width) {
	this->height = height;
	this->width = width;
	
	//prvo ide x pa y pozicija slike u pristupu

	this->slika = new Piksel*[width];

	for (unsigned int i = 0; i < width; i++) {
		slika[i] = new Piksel[height];
	}
}

Slika::~Slika() {
	for (unsigned int i = 0; i < width;i++) {
		delete slika[i];
	}
	delete slika;
}

const Piksel Slika::operator[](const Pozicija& pozicija) const {
	return slika[pozicija.getX()][pozicija.getY()];
}

Slika::Slika(const Slika& slika1) : Slika(slika1.height, slika1.width) {
	for (unsigned int i = 0; i < width; i++) {
		for (unsigned int j = 0; j < height; j++) {
			slika[i][j] = slika1[Pozicija(i,j)];
		}
	}
}

Slika::Slika(Slika&& slika1) : Slika(slika1.height, slika1.width) {
	for (unsigned int i = 0; i < width; i++) {
		for (unsigned int j = 0; j < height; j++) {
			slika[i][j] = slika1[Pozicija(i, j)];
		}
	}
	slika1.~Slika();
}

void Slika::setPiksel(const Piksel& piksel, const Pozicija& pozicija) {
	slika[pozicija.getX()][pozicija.getY()] = piksel;
}

unsigned long int Slika::size() const {
	return 24 * width * height;
}

ostream& operator<<(ostream& os, const Slika& slika) {
	cout << "velicina " << slika.size() << endl << endl;
	for (int i = 0; i < slika.width; i++) {
		for (int j = 0; j < slika.height; j++) {
			cout << slika[Pozicija(i, j)]<<endl;
		}
	}
	return os;
}

class Crno_Bela_Slika : public Slika {
public:
	void setPiksel(const Piksel&, const Pozicija&);
	Crno_Bela_Slika() : Slika() {}
	Crno_Bela_Slika(unsigned int w, unsigned int h) : Slika(w, h) {}
	Crno_Bela_Slika(const Crno_Bela_Slika& sl) : Slika(sl) {}
	Crno_Bela_Slika(Crno_Bela_Slika&& sl) : Slika(sl) {}
};

void Crno_Bela_Slika::setPiksel(const Piksel& piksel, const Pozicija& pozicija) {
	unsigned int X;
	X = (piksel.getR() / 3 + piksel.getG() / 3 + piksel.getB() / 3)>127?1:0;
	slika[pozicija.getX()][pozicija.getY()] = Piksel(X, X, X);
}
void main() {
	Slika slika(3, 4);
	Slika slika2 = slika;
	Slika slika3 = move(slika);
	
}