#include "Element.h"

ostream& operator<<(ostream& os, const Element& el) {
	os << el.get_natpis();
	return os;
}


bool operator>(const Binarni_Operator& op1, const Binarni_Operator& op2) {
	return op1.get_priority() > op2.get_priority();
}