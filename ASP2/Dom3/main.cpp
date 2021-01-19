
#include <iostream>
using namespace std;



#include "DigitalnoStablo.h"
#include "Header.h"
using namespace std::chrono;

void meni() {
	cout << "1. Unesi predefinisane tekstove \n2. Unesi tekstove sa ulaza\n3. Umetni rec\n4. Pronadji rec\n5. Predikcija\n6. Izadji\n\n";
}
void main(){
	 Dict dict;
	 high_resolution_clock::time_point t1, t2;
	 int n;
	 char str[20];
	 meni();
	 while (1) {
		 cout << "Unesite opciju\n";
		 cin >> n;
		 switch(n) {
		 case 1:
			 t1 = high_resolution_clock::now();
			 dict.umetniSve();
			 t2 = high_resolution_clock::now();
			 duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
			 std::cout << "vreme izvrsavanja: " << time_span.count() <<endl;
			 break;
		 case 2:
			 cout << "Unesite ime dat\n";
			 cin >> str;
			 dict.umetni(str);
			 break;
		 case 3:
			 cout << "Unesite rec\n";
			 cin >> str;
			 dict.umetniRec(str);
			 break;
		 case 4:
			 cout << "Unesite rec\n";
			 cin >> str;
			 dict.pretraga(str);
			 break;
		 case 5:
			 cout << "Unesite rec\n";
			 cin >> str;
			 dict.predikcija(str);
			 break;
		 case 6:
			 return;
		 default:
			 cout << "Unesite valjanu vrednost" << endl;
		 }
	 }
	 
	 
	 
	
}