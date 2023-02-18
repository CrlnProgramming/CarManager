#include "ByModelCarComparer.h"

int CarManagerWindowsFormsUI::OrderProviders::ByModelCarComparer::Compare(Car ^ x, Car ^ y)
{
	return x->Model->CompareTo(y->Model);
}
