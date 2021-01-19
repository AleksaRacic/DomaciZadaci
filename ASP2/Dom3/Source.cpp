#include "Header.h"

#include <fstream>
#include <iostream>

#include <filesystem>
namespace fs = std::experimental::filesystem;

using namespace std;

QWERTY::QWERTY() {
	qwerty = new vector<vector<char>>;
	qwerty->push_back(vector<char>{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'});
	qwerty->push_back(vector<char>{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '0'});
	qwerty->push_back(vector<char>{'z', 'x', 'c', 'v', 'b', 'n', 'm', '0', '0', '0'});
}

QWERTY::~QWERTY() {
	delete qwerty;
}

Dict::Dict() {
	tree = new DigitalnoStablo();
	nedozvoljeni_karakteri = new unordered_set<char>({ '.', ',','-','@',';','(',')',':','!','_','?','"' });
}

Dict::~Dict() {
	delete tree;
	delete nedozvoljeni_karakteri;
}



void Dict::umetni(const char *ime) {
	ifstream dat;
	//char line[25];
	string line;
	dat.open(ime);
	if (!dat.is_open()) {
		cout << "Nemoguce otvoriti datoteku: " << ime << endl;
		return;
	}
	while (!dat.eof()) {
		//dat >> std::noskipws;
		//dat >>std::ws>> line>> std::ws;
		getline(dat >> std::ws, line);
		string tmp = "";
		for (unsigned int i = 0; i < line.size(); i++) {

			if (nedozvoljeni_karakteri->count(line[i]) != 0) {
				tmp = "";
				continue;
			}
			if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
				if (tmp.size() != 0) {
					tree->umetni(tmp.c_str());
					tmp = "";
				}
				continue;
			}
			if (line[i] < 'a') {
				tmp += (line[i] + char(32));
			}
			else {
				tmp += line[i];
			}


		}

	}
	dat.close();
	//cout << "Uneto " << ime << endl;
	//tree->obidji(cout);

}


void Dict::umetni(vector<const char*> imena) {
	for (auto *ime : imena) {
		umetni(ime);
	}
}

void Dict::umetni(string ime) {
	ifstream dat;
	//char line[25];
	string line;
	dat.open(ime);
	if (!dat.is_open()) {
		cout << "Nemoguce otvoriti datoteku: " << ime << endl;
		return;
	}
	while (!dat.eof()) {
		//dat >> std::noskipws;
		//dat >>std::ws>> line>> std::ws;
		getline(dat >> std::ws, line);
		string tmp = "";
		for (unsigned int i = 0; i < line.size(); i++) {

			if (nedozvoljeni_karakteri->count(line[i]) != 0) {
				tmp = "";
				continue;
			}
			if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
				if (tmp.size() != 0) {
					tree->umetni(tmp.c_str());
					tmp = "";
				}
				continue;
			}
			if (line[i] < 'a') {
				tmp += (line[i] + char(32));
			}
			else {
				tmp += line[i];
			}


		}

	}
	dat.close();
	//cout << "Uneto " << ime << endl;
	//tree->obidji(cout);

}

void Dict::umetniSve() {
	string path = "C:/Users/HP/Documents/Visual Studio 2017/Projects/ASP_dz3/ASP_dz3";
	for (auto& p : fs::directory_iterator(path)) {
		//cout << p.path() << endl;
		if (p.path().extension() == ".txt")
			umetni(p.path().string());
		//tree->ispisiStatistiku(cout);
	}
	tree->ispisiStatistiku(cout);
}
bool Dict::pretraga(const char* key) {
	DigitalnoStablo::DSList *list = tree->pronadjiCvor(key);
	if (list == 0) {
		cout << "Neuspela pretraga kljuca " << key << endl;
		return 0;
	}
	else {
		cout << "Uspesna pretraga kljuca " << key << " frekvencija: " << list->dohvatiFrekvenciju() << endl;
		return 1;
	}
}

bool Dict::umetniRec(const char* rec) {
	return tree->umetni(rec);
}

vector<char> QWERTY::nadjiSuseda(char a) {
	vector<char> susedi;
	//susedi.push_back(a);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if ((*qwerty)[i][j] == a) {
				if (i > 0) susedi.push_back((*qwerty)[i - 1][j]);
				if (i < 2) susedi.push_back((*qwerty)[i + 1][j]);
				if (j > 0) susedi.push_back((*qwerty)[i][j - 1]);
				if (j < 9) susedi.push_back((*qwerty)[i][j + 1]);
				return susedi;
			}
		}
	}
	return susedi;
}

void Dict::predikcija(const char *kljuc) {
	vector<DigitalnoStablo::DSCvor*> predikcije;
	predikcije = tree->predict(kljuc, 5);


	for (auto i = predikcije.rbegin(); i != predikcije.rend(); ++i) {
		cout << tree->findString(*i) << " Frekvencija: " << (*i)->dohvatiFrekvenciju() << endl;
	}
}

