#include "Namirnica.h"

bool operator== (const Namirnica& nam1, const Namirnica& nam2) {
	return nam1.get_naziv() == nam2.get_naziv();
}

ostream& operator<<(ostream& os, const Namirnica& nam) {
	os << nam.naziv << "-" << nam.nut_vr;
	return os;
}