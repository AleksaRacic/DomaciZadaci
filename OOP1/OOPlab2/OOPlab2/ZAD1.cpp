#include <iostream>
#include <random>
#include <vector>
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


class Pozicija {
private:
	unsigned int x, y;
public:
	unsigned int getX() const { return x; }
	unsigned int getY() const { return y; }
	Pozicija(unsigned int, unsigned int);
};

class Vreme {
private:
	int hrs, mins, sec;
public:
	Vreme(int, int, int);
	Vreme();
	friend ostream& operator<<(ostream&, const Vreme&);
	friend bool operator>(const Vreme&, const Vreme&);
};

class Slika {
private:
	friend class Crno_Bela_Slika;
	friend class Sarena_Slika;
	friend class Siva_Slika;
protected:
	unsigned int height, width;
	Piksel **slika;
public:
	Vreme vreme;
	Slika();
	Slika(unsigned int, unsigned int, const Vreme&);
	~Slika();
	Slika(const Slika&);
	Slika(Slika&&);
	const Piksel operator[](const Pozicija&)const;
	virtual void setPiksel(const Piksel&, const Pozicija&);
	unsigned long int size()const;
	friend ostream& operator<<(ostream&, const Slika&);
	unsigned int getHeight() const;
	unsigned int getWidth() const;
	Slika operator=(const Slika&);
};

class Galerija {
private:
	friend class Uredjena_Galerija;
	vector<Slika> slike;
public:
	Galerija() {};
	Galerija operator+=(const Slika&);
	Slika operator[](int);
	int size();
	unsigned long int getSize();
	friend ostream& operator<<(ostream&, const Galerija&);
	//Galerija(const Galerija&) = default;
	//Galerija operator=(const Galerija&) = default;

};


class Uredjena_Galerija : public Galerija {
public:
	Uredjena_Galerija() :Galerija() {};
	Uredjena_Galerija operator+=(const Slika&);
	//friend ostream& operator<<(ostream, const Uredjena_Galerija&);
};


Slika Slika::operator=(const Slika& slika) {
	Slika slika1(slika);
	return slika1;
}
class Sarena_Slika : public Slika {
public:
	void setPiksel(const Piksel&, const Pozicija&);
	Sarena_Slika(const Slika&, const Slika&);
	Sarena_Slika(unsigned int, unsigned int, const Vreme&);
	Sarena_Slika(const Sarena_Slika& sl) : Slika(sl) {}
	Sarena_Slika(Sarena_Slika&& sl) : Slika(sl) {}
};

class Siva_Slika : public Slika {
public:
	void setPiksel(const Piksel&, const Pozicija&);
	Siva_Slika() : Slika() {}
	Siva_Slika(unsigned int w, unsigned int h, const Vreme& vreme) : Slika(w, h, vreme) {}
	Siva_Slika(const Siva_Slika& sl) : Slika(sl) {}
	Siva_Slika(Siva_Slika&& sl) : Slika(sl) {}
};

class Crno_Bela_Slika : public Slika {
public:
	void setPiksel(const Piksel&, const Pozicija&);
	Crno_Bela_Slika() : Slika() {}
	Crno_Bela_Slika(unsigned int w, unsigned int h, const Vreme& vreme) : Slika(w, h, vreme) {}
	Crno_Bela_Slika(const Crno_Bela_Slika& sl) : Slika(sl) {}
	Crno_Bela_Slika(Crno_Bela_Slika&& sl) : Slika(sl) {}
	Crno_Bela_Slika(const Siva_Slika&);
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



Pozicija::Pozicija(unsigned int x, unsigned int y) {
	this->x = x;
	this->y = y;
}

int operator-(const Pozicija& lPozicija, const Pozicija& rPozicija) {
	unsigned int ras_kol = lPozicija.getX() > rPozicija.getX() ? lPozicija.getX() - rPozicija.getX() : lPozicija.getX() - rPozicija.getX();
	unsigned int ras_vr = lPozicija.getY() > rPozicija.getY() ? lPozicija.getY() - rPozicija.getY() : lPozicija.getY() - rPozicija.getY();
	return ras_kol + ras_vr;
}


unsigned int Slika::getWidth() const {
	return width;
}

unsigned int Slika::getHeight() const {
	return height;
}

Slika::Slika(unsigned int height, unsigned int width, const Vreme& vreme) {
	this->height = height;
	this->width = width;
	this->vreme = vreme;
	//prvo ide x pa y pozicija slike u pristupu

	this->slika = new Piksel*[width];

	for (unsigned int i = 0; i < width; i++) {
		slika[i] = new Piksel[height];
	}
}

Slika::~Slika() {
	if (slika != nullptr) {
		for (unsigned int i = 0; i < width; i++) {
			delete slika[i];
			slika[i] = nullptr;
		}
		delete slika;
		slika = nullptr;
	}
	
}

const Piksel Slika::operator[](const Pozicija& pozicija) const {
	if (pozicija.getX() < this->getWidth() && pozicija.getY() < this->getHeight()) {
		return slika[pozicija.getX()][pozicija.getY()];
	}
	else {
		return(Piksel(0, 0, 0));
	}
	
}

Slika::Slika(const Slika& slika1) : Slika(slika1.height, slika1.width, slika1.vreme) {
	for (unsigned int i = 0; i < width; i++) {
		for (unsigned int j = 0; j < height; j++) {
			slika[i][j] = slika1[Pozicija(i,j)];
		}
	}
}

Slika::Slika(Slika&& slika1) : Slika(slika1.height, slika1.width, slika1.vreme) {
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




Crno_Bela_Slika::Crno_Bela_Slika(const Siva_Slika& Sslika) : Slika(Sslika.getWidth(),Sslika.getHeight(), Sslika.vreme){
	Pozicija pozicija(0, 0);
	for (unsigned int i = 0; i < width; i++) {
		for (unsigned int j = 0; j < height; j++) {
			pozicija = Pozicija(i, j);
			setPiksel(Sslika[pozicija], pozicija);
		}
	}
}

void Crno_Bela_Slika::setPiksel(const Piksel& piksel, const Pozicija& pozicija) {
	unsigned int X;
	X = (piksel.getR() / 3 + piksel.getG() / 3 + piksel.getB() / 3)>127?1:0;
	slika[pozicija.getX()][pozicija.getY()] = Piksel(X, X, X);
}

Vreme::Vreme() {
	this->hrs = 0;
	this->mins = 0;
	this->sec = 0;
}

Vreme::Vreme(int hrs, int mins, int sec) {
	this->hrs = hrs;
	this->mins = mins;
	this->sec = sec;
}

ostream& operator<<(ostream& os, const Vreme& vreme) {
	cout << vreme.hrs << ":" << vreme.mins << ":" << vreme.sec;
	return os;
}

bool operator>(const Vreme& vreme1, const Vreme& vreme2) {
	if (vreme1.hrs > vreme2.hrs) {
		return true;
	}
	else if (vreme1.hrs < vreme2.hrs) {
		return false;
	}
	else {
		if (vreme1.mins > vreme2.mins) {
			return true;
		}
		else if (vreme1.mins<vreme2.mins){
			return false;
		}
		else {
			if (vreme1.sec > vreme2.sec) {
				return true;
			}
			else if (vreme1.sec < vreme2.sec) {
				return false;
			}
			else {
				return false;
			}
		}
	}
}

ostream& operator<<(ostream& os, const Slika& slika) {
	cout << "Slika: " << slika.vreme << " velicina: " << slika.size() << endl << endl;
	for (unsigned int i = 0; i < slika.width; i++) {
		for (unsigned int j = 0; j < slika.height; j++) {
			cout << slika[Pozicija(i, j)] << endl;
		}
	}
	return os;
}

Sarena_Slika::Sarena_Slika(unsigned int w, unsigned int h, const Vreme& vreme) : Slika(w,h,vreme){
	Piksel piksel(0, 0, 0);
	Pozicija pozicija(0, 0);
	for (unsigned int i = 0; i < w; i++) {
		for (unsigned int j = 0; j < h; j++) {
			do {
				piksel = Piksel(rand() % 256, rand() % 256, rand() % 256);
				pozicija=Pozicija(i,j);
			} while (this->operator[](Pozicija(i + 1, j)) == piksel || this->operator[](Pozicija(i - 1, j)) == piksel, this->operator[](Pozicija(i, j - 1)) == piksel || this->operator[](Pozicija(i, j + 1)) == piksel);
			


			setPiksel(piksel, pozicija);
		}
	}
}
void Sarena_Slika::setPiksel(const Piksel& piksel, const Pozicija& pozicija) {
	int i = pozicija.getX();
	int j = pozicija.getY();
	if (this->operator[](Pozicija(i + 1, j)) == piksel || this->operator[](Pozicija(i - 1, j)) == piksel, this->operator[](Pozicija(i, j - 1)) == piksel || this->operator[](Pozicija(i, j + 1)) == piksel) {
		
	}
	else {
		this->slika[pozicija.getX()][pozicija.getY()] = piksel;
	}
}
Sarena_Slika::Sarena_Slika(const Slika& slika1, const Slika& slika2) : Slika(slika1.getWidth(), slika1.getHeight(), (slika1.vreme > slika2.vreme?slika2.vreme:slika1.vreme)) {
	int r, g, b;
	Pozicija pozicija(0, 0);
	for (unsigned int i = 0; i < slika1.width; i++) {
		for (unsigned int j = 0; j < slika1.height; j++) {
			pozicija = Pozicija(i, j);
			r = (slika1[pozicija].getR() + slika2[pozicija].getR()) / 2;
			g = (slika1[pozicija].getG() + slika2[pozicija].getG()) / 2;
			b = (slika1[pozicija].getB() + slika2[pozicija].getB()) / 2;
			Slika::setPiksel(Piksel(r, g, b), pozicija);
		}
	}
}

void Siva_Slika::setPiksel(const Piksel& piksel, const Pozicija& pozicija) {
	unsigned int X = (piksel.getR() + piksel.getG() + piksel.getB()) / 3;
	Slika::setPiksel(Piksel(X, X, X), pozicija);
}

Galerija Galerija::operator+=(const Slika& slika) {
	slike.push_back(slika);
	return *this;
}
int Galerija::size() {
	return slike.size();
}

Slika Galerija::operator[](int index) {
	return slike[index];
}

unsigned long int Galerija::getSize() {
	unsigned long int size = 0;
	for (auto slika : slike) {
		size += slika.size();
	}
	return size;
}

ostream& operator<<(ostream& os, const Galerija& galerija) {
	for (auto slika : galerija.slike) {
		cout << slika << endl;
		//cout << "nesto";
	}
	return os;
}


Uredjena_Galerija Uredjena_Galerija::operator+=(const Slika& slika) {
	auto ti = slike.end();
	for (auto it = slike.begin(); it < slike.end(); ++it) {
		if (it->vreme > slika.vreme) {
			ti = it;
			break;
		}
	}
	slike.insert(ti, slika);
	return *this;
}


void main() {
	Vreme vreme(23, 24, 32);
	Vreme vreme1(23, 41, 23);
	Vreme vreme2(12, 45, 65);
	Slika slika(2, 2, vreme);
	Slika slika2 = slika;
	Slika slika3 = move(slika);
	Crno_Bela_Slika slika4(2, 2, vreme);
	Sarena_Slika slika5(2, 2, vreme);
	Siva_Slika slika6(2, 2, vreme1);
	Crno_Bela_Slika slika7 = (Crno_Bela_Slika)slika6;
	Uredjena_Galerija gal;
	gal += slika5;
	gal += slika6;
	gal += slika4;
	//cout << slika6;
	//cout << slika5;
	cout << gal;
	Sarena_Slika slik7(slika5, slika6);
	
}