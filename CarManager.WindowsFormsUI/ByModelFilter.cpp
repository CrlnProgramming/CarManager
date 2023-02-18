#include "ByModelFilter.h"

using namespace CarManagerWindowsFormsUI::Filters;

ByModelFilter::ByModelFilter(CheckBox ^ checkBox, TextBox ^ model)
{
	this->checkBox = checkBox;
	this->model = model;
}

bool ByModelFilter::IsEnable()
{
	return this->checkBox->Checked;
}

array<Car^>^ ByModelFilter::Filter(array<Car^>^ input)
{
	List<Car^>^ result = gcnew List<Car^>();

	String^ modelFilteredBy = this->model->Text->ToUpper();

	for each (Car^ var in input)
	{
		if (var->Model->ToUpper()->Equals(modelFilteredBy)) {
			result->Add(var);
		}
	}

	return result->ToArray();
}
