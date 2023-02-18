#include "CreateCarForm.h"

using namespace CarManager::Logic;
using namespace CarManagerWindowsFormsUI::Formaters;



void CarManagerWindowsFormsUI::CreateCarForm::CustomInitialize()
{

}

System::Void CarManagerWindowsFormsUI::CreateCarForm::SubmitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Person^ person;
	CarNumber^ carNumber;
	Car^ car;
	try
	{
		person = gcnew Person(NameTextBox->Text, SurNameTextBox->Text, AddressesTextBox->Text);

		carNumber = gcnew CarNumber(RegionCodeTextBox->Text, DigitalCodeTextBox->Text, LiteralCodeTextBox->Text);

		car = gcnew Car(ModelTextBox->Text, carNumber, ColorTextBox->Text, person, LastInspectionDatePicker->Value);
	}
	catch (Exception^ e)
	{
		this->ValidationErrorTextBox->Text = e->Message;
		return;
	}
	

	this->service->AddCar(car);

	this->Close();
	
}
#pragma region  Formatters
void CarManagerWindowsFormsUI::CreateCarForm::CreateFormaters()
{
	Formaters = gcnew array<ITextFormater^>{
		gcnew CamelCaseTextFormatter()
	};

	this->ModelTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::CreateCarForm::OnTextChangedFormatsApplier);
	this->ColorTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::CreateCarForm::OnTextChangedFormatsApplier);
	this->NameTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::CreateCarForm::OnTextChangedFormatsApplier);
	this->SurNameTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::CreateCarForm::OnTextChangedFormatsApplier);
}

void CarManagerWindowsFormsUI::CreateCarForm::OnTextChangedFormatsApplier(System::Object ^sender, System::EventArgs ^e)
{
	TextBox^ textBox = (TextBox^)sender;
	String^ text = textBox->Text;

	if (String::IsNullOrWhiteSpace(text)) {
		return;
	}

	for each (ITextFormater^ var in this->Formaters)
	{
		text = var->Format(text);
	}

	textBox->Text = text;

	textBox->SelectionStart = text->Length; // add some logic if length is 0
	textBox->SelectionLength = 0;

}

#pragma endregion


