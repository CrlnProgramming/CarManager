#include "MainForm.h"
#include"CreateCarForm.h"
#include"EditCarForm.h"

#include"ByModelFilter.h"
#include"HaveNoInspectionThisYear.h"

#include"SortByModelOrderProvider.h"

using namespace CarManager::Logic;
using namespace CarManagerWindowsFormsUI;

void MainForm::CustomInitiaize()
{
	service = gcnew CarService();
	Person^ person = gcnew Person("Сергей", "Петрович", "Gagarina 37A");
	
	CarNumber^ carNumber = gcnew CarNumber("AK", "1234", "AB");

	Car^ car = gcnew Car("Волга", carNumber, "Серый", person, DateTime::Now);

	service->AddCar(car);



}

void MainForm::CarTableInitialize()
{
	DataGridViewTextBoxColumn^ modelColumn = gcnew DataGridViewTextBoxColumn();
	modelColumn->HeaderText = "Модель";
	modelColumn->Name = "Model";
	modelColumn->DataPropertyName = "Model";

	DataGridViewTextBoxColumn^ numberColumn = gcnew DataGridViewTextBoxColumn();
	numberColumn->HeaderText = "Номер";
	numberColumn->Name = "Number";
	numberColumn->DataPropertyName = "Number";

	DataGridViewTextBoxColumn^ colorColumn = gcnew DataGridViewTextBoxColumn();
	colorColumn->HeaderText = "Цвет";
	colorColumn->Name = "Color";
	colorColumn->DataPropertyName = "Color";

	DataGridViewTextBoxColumn^ ownerColumn = gcnew DataGridViewTextBoxColumn();
	ownerColumn->HeaderText = "Владелец";
	ownerColumn->Name = "Owner";
	ownerColumn->DataPropertyName = "Owner";

	DataGridViewTextBoxColumn^ lastInspectionColumn = gcnew DataGridViewTextBoxColumn();
	lastInspectionColumn->HeaderText = "Техосмотр";
	lastInspectionColumn->Name = "LastInspectionDate";
	lastInspectionColumn->DataPropertyName = "LastInspectionDate";

	DataGridViewButtonColumn^ editButtons = gcnew DataGridViewButtonColumn();
	editButtons->HeaderText = "Редактировать";
	editButtons->Name = "EditCar";
	editButtons->Text = "Редактировать";
	editButtons->UseColumnTextForButtonValue = true;
	this->CarTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CarManagerWindowsFormsUI::MainForm::OnEditButtonsCellClick);

	this->CarTable->Columns->Add(modelColumn);
	this->CarTable->Columns->Add(numberColumn);
	this->CarTable->Columns->Add(colorColumn);
	this->CarTable->Columns->Add(ownerColumn);
	this->CarTable->Columns->Add(lastInspectionColumn);
	this->CarTable->Columns->Add(editButtons);

	this->CarTable->AutoGenerateColumns = false;
	this->CarTable->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

	service->Update += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::MainForm::OnCarsUpdate);

	this->CarTable->DataSource = service->GetCars();

}
#pragma region CarFilters
void MainForm::CreateFilters()
{
	this->Filters = gcnew array<ICarFilter^>{
		gcnew ByModelFilter(this->ModelFilterCheckBox, this->ModelFilterTextBox),
		gcnew HaveNoInspectionThisYear(this->HaveNoInspectionThisYearFilterCheckBox)
	};
}

System::Void MainForm::ApplyFiltersButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	array<Car^>^ currCars = (array<Car^>^)this->service->GetCars();

	for each (ICarFilter^ var in this->Filters)
	{
		if (var->IsEnable()) {
			currCars = var->Filter(currCars);
		}
	}

	ApplyOrderProviders(currCars);

	this->CarTable->DataSource = currCars;

	return System::Void();
}
#pragma endregion

#pragma OrderProviders

void MainForm::CreateOrderProviders()
{
	this->OrderProviders = gcnew array<IOrderProvider^>{
		gcnew SortByModelOrderProvider(this->SortByModelOrderProviderCheckBox)
	};
}

void MainForm::ApplyOrderProviders(array<Car^>^ input)
{
	for each (IOrderProvider^ var in this->OrderProviders)
	{
		if (var->IsEnable()) {
			var->ReOrder(input);
		}
	}
}

#pragma endregion


void MainForm::OnCarsUpdate(System::Object ^sender, System::EventArgs ^e)
{
	this->CarTable->DataSource = ((CarService^)sender)->GetCars();
	this->CarTable->Refresh();
}

System::Void CarManagerWindowsFormsUI::MainForm::CreateCarFormNav_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	CreateCarForm^ next = gcnew CreateCarForm(this->service);
	
	next->Show();
	next->Focus();

	return System::Void();
}


void CarManagerWindowsFormsUI::MainForm::OnEditButtonsCellClick(System::Object ^sender, System::Windows::Forms::DataGridViewCellEventArgs ^e)
{
	int columnIndex = e->ColumnIndex;

	if (e->RowIndex == -1)
	{
		return;
	}

	if (columnIndex == this->CarTable->Columns["EditCar"]->Index)
	{
		array<Car^>^ cars = (array<Car^>^)(this->CarTable->DataSource);

		int i = e->RowIndex;

		EditCarForm^ next = gcnew EditCarForm(this->service,cars[i]);

		next->Show();
		next->Focus();

		next->Closed += gcnew System::EventHandler(this, &CarManagerWindowsFormsUI::MainForm::OnEditFormClosed);

	}
}


void CarManagerWindowsFormsUI::MainForm::OnEditFormClosed(System::Object ^sender, System::EventArgs ^e)
{
	this->CarTable->DataSource = this->service->GetCars();
}
