#include "Human.h"
#include "Base.h"

void Human::arrive()
{
	if (isActive) throw "Human is already on the base.";
	isActive = true;
	Base::set_People(Base::get_People() + 1);
}

bool Human::leave()
{
	if (!isActive) return 0;
	if (Base::get_People() <= 0) throw "No people on the base.";
	isActive = false;
	Base::set_People(Base::get_People() - 1);
	return 1;
}