#include "Element.h"
#include "Exceptions.h"
#include "Generator.h"
#include "Izraz.h"
#include "Lista.h"

void main() {
	Izraz iz;
	iz += &Leva_Zagrada();
	iz += &Operand("A");
	iz += &Sabiranje();
	iz += &Operand("B");
	iz += &Desna_Zagrada();
	iz += &Sabiranje();
	iz += &Leva_Zagrada();
	iz += &Operand("A");
	iz += &Sabiranje();
	iz += &Operand("B");
	iz += &Desna_Zagrada();
	cout << iz<<endl;
	Generator *generator = Generator::instanca();
	Izraz izlaz = (*generator)(iz);
	cout << izlaz << endl;
}