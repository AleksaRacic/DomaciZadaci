#include "Element.h"
#include "Exceptions.h"
#include "Generator.h"
#include "Izraz.h"
#include "Lista.h"

void main() {
	try {
		Izraz iz;
		iz += Leva_Zagrada();
		iz += Operand("A");
		iz += Sabiranje();
		iz += Operand("B");
		iz += Desna_Zagrada();
		iz += Sabiranje();
		iz += Leva_Zagrada();
		iz += Operand("A");
		iz += Sabiranje();
		iz += Operand("B");
		iz += Desna_Zagrada();
		iz += Mnozenje();
		iz += Operand("C");

		Izraz iz2;
		iz2 += Operand("A");
		iz2 += Sabiranje();
		iz2 += Operand("B");
		iz2 += Mnozenje();
		iz2 += Operand("C");
		iz2 += Desna_Zagrada();
		iz2 += Sabiranje();
		iz2 += Operand("B");
		cout << iz << endl;
		Generator *generator = Generator::instanca();
		Izraz izlaz = (*generator)(iz);
		cout << izlaz << endl;

		cout << iz2 << endl;
		izlaz = (*generator)(iz2);
		cout << izlaz << endl;
	}
	catch (exception& err) {
		cout << err.what()<<endl;
	}
}