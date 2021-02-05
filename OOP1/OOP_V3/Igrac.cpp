#include "Igrac.h"

bool operator==(const Igrac& igrac1, const Igrac& igrac2) {
	return (igrac1.get_ime() == igrac2.get_ime() && igrac1.get_vr() == igrac2.get_vr());
}

ostream& operator<<(ostream& os, const Igrac& ig) {
	os << ig.get_ime() << "#" << ig.get_vr();
	return os;
}