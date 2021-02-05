#include "Priveligovani.h"

void Privilegovani::add_player(Igrac& ig, int i) {
	if (ig.get_vr() < min_vr) throw(errPrik());
	else Tim::add_player(ig, i);
}

ostream& Privilegovani::print(ostream& os) const {
	Tim::print(os) << "(" << min_vr << ")";
	return os;
}
