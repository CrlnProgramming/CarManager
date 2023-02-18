#include "SortByModelOrderProvider.h"
#include"ByModelCarComparer.h"
#include"QuickSorter.h"

using namespace CarManagerWindowsFormsUI::OrderProviders;

SortByModelOrderProvider::SortByModelOrderProvider(CheckBox^ checkBox)
{
	this->checkBox = checkBox;
	this->comparer = gcnew ByModelCarComparer();
}

bool SortByModelOrderProvider::IsEnable()
{
	return this->checkBox->Checked;
}

void SortByModelOrderProvider::ReOrder(array<Car^>^ input)
{
	QuicSorter::Sort(input, this->comparer);
}
