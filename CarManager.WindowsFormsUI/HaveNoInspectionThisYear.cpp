#include "HaveNoInspectionThisYear.h"
using namespace CarManagerWindowsFormsUI::Filters;

HaveNoInspectionThisYear::HaveNoInspectionThisYear(CheckBox ^ checkBox)
{
	this->checkBox = checkBox;
}

bool HaveNoInspectionThisYear::IsEnable()
{
	return this->checkBox->Checked;
}

array<Car^>^ HaveNoInspectionThisYear::Filter(array<Car^>^ input)
{
	int thisYear = DateTime::Now.Year;

	List<Car^>^ result = gcnew List<Car^>();

	for each (Car^ var in input)
	{
		if (var->LastInspectionDate.Year < thisYear) {
			result->Add(var);
		}
	}

	return result->ToArray();
}
