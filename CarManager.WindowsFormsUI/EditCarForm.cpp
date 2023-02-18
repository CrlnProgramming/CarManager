#include "EditCarForm.h"

using namespace CarManager::Logic;
using namespace CarManagerWindowsFormsUI::Formaters;



void CarManagerWindowsFormsUI::EditCarForm::CustomInitialize()
{
	this->NameTextBox->Text = this->EditedCar->Owner->GetFirstName();
	this->SurNameTextBox->Text = this->EditedCar->Owner->GetSurName();
	this->AddressesTextBox->Text = this->EditedCar->Owner->GetAddress();

	this->RegionCodeTextBox->Text = this->EditedCar->Number->GetRegionCode();
	this->DigitalCodeTextBox->Text = this->EditedCar->Number->GetDigitalCode();
	this->LiteralCodeTextBox->Text = this->EditedCar->Number->GetLiteralCode();

	this->ModelTextBox->Text = this->EditedCar->Model;
	this->ColorTextBox->Text = this->EditedCar->Color;
	this->LastInspectionDatePicker->Value = this->EditedCar->LastInspectionDate;


}

System::Void CarManagerWindowsFormsUI::EditCarForm::SubmitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Person^ person = EditedCar->Owner;
	CarNumber^ carNumber = EditedCar->Number;
	Car^ car = EditedCar;
	try
	{
		person->SetFirstName(NameTextBox->Text);
		person->SetSurName(SurNameTextBox->Text);
		person->SetAddress(AddressesTextBox->Text);

		carNumber->SetRegionCode(RegionCodeTextBox->Text);
		carNumber->SetDigitalCode(DigitalCodeTextBox->Text);
		carNumber->SetLiteralCode(LiteralCodeTextBox->Text);

		car->Model = ModelTextBox->Text;
		car->Color = ColorTextBox->Text;
		car->LastInspectionDate = LastInspectionDatePicker->Value;
	}
	catch (Exception^ e)
	{
		this->ValidationErrorTextBox->Text = e->Message;
		return;
	}

	this->Close();

}
#pragma region  Formatters
void CarManagerWindowsFormsUI::EditCarForm::CreateFormaters()
{
	Formaters = gcnew array<ITextFormater^>{
		gcnew CamelCaseTextFormatter()
	};

	this->ModelTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::EditCarForm::OnTextChangedFormatsApplier);
	this->ColorTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::EditCarForm::OnTextChangedFormatsApplier);
	this->NameTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::EditCarForm::OnTextChangedFormatsApplier);
	this->SurNameTextBox->TextChanged += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::EditCarForm::OnTextChangedFormatsApplier);
}

void CarManagerWindowsFormsUI::EditCarForm::OnTextChangedFormatsApplier(System::Object ^sender, System::EventArgs ^e)
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


