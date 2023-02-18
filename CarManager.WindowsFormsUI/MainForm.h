#pragma once
#include"ICarFilter.h"
#include"IOrderProvider.h"

namespace CarManagerWindowsFormsUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CarManager::Logic;
	using namespace CarManagerWindowsFormsUI::Filters;
	using namespace CarManagerWindowsFormsUI::OrderProviders;
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			CustomInitiaize();
			CarTableInitialize();
			CreateFilters();
			CreateOrderProviders();
			//
		}
	private: System::Windows::Forms::GroupBox^  OrderProvidersCheckBox;
	public:

	private: System::Windows::Forms::CheckBox^  SortByModelOrderProviderCheckBox;

	public:

#pragma region  Custmom
	private:
		CarService^ service;
		void OnCarsUpdate(System::Object ^sender, System::EventArgs ^e);

		void CustomInitiaize();
		void CarTableInitialize();

		System::Collections::Generic::IEnumerable<ICarFilter^>^ Filters;
		void CreateFilters();
		System::Void ApplyFiltersButton_Click(System::Object^  sender, System::EventArgs^  e);

		System::Collections::Generic::IEnumerable<IOrderProvider^>^ OrderProviders;
		void CreateOrderProviders();
		void ApplyOrderProviders(array<Car^>^);

		void OnEditButtonsCellClick(System::Object ^sender, System::Windows::Forms::DataGridViewCellEventArgs ^e);

		void OnEditFormClosed(System::Object ^sender, System::EventArgs ^e);
#pragma endregion
		


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  CarTable;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::MenuStrip^  Navigation;


	private: System::Windows::Forms::ToolStripMenuItem^  CreateCarFormNav;
	private: System::Void CreateCarFormNav_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Windows::Forms::GroupBox^  FilterBox;
	private: System::Windows::Forms::Button^  ApplyFiltersButton;
	private: System::Windows::Forms::CheckBox^  HaveNoInspectionThisYearFilterCheckBox;

	private: System::Windows::Forms::TextBox^  ModelFilterTextBox;
	private: System::Windows::Forms::CheckBox^  ModelFilterCheckBox;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CarTable = (gcnew System::Windows::Forms::DataGridView());
			this->Navigation = (gcnew System::Windows::Forms::MenuStrip());
			this->CreateCarFormNav = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FilterBox = (gcnew System::Windows::Forms::GroupBox());
			this->HaveNoInspectionThisYearFilterCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ModelFilterTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ModelFilterCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ApplyFiltersButton = (gcnew System::Windows::Forms::Button());
			this->OrderProvidersCheckBox = (gcnew System::Windows::Forms::GroupBox());
			this->SortByModelOrderProviderCheckBox = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CarTable))->BeginInit();
			this->Navigation->SuspendLayout();
			this->FilterBox->SuspendLayout();
			this->OrderProvidersCheckBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// CarTable
			// 
			this->CarTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->CarTable->Location = System::Drawing::Point(75, 325);
			this->CarTable->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->CarTable->Name = L"CarTable";
			this->CarTable->Size = System::Drawing::Size(891, 290);
			this->CarTable->TabIndex = 0;
			// 
			// Navigation
			// 
			this->Navigation->ImageScalingSize = System::Drawing::Size(20, 20);
			this->Navigation->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->CreateCarFormNav });
			this->Navigation->Location = System::Drawing::Point(0, 0);
			this->Navigation->Name = L"Navigation";
			this->Navigation->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->Navigation->Size = System::Drawing::Size(1021, 28);
			this->Navigation->TabIndex = 1;
			this->Navigation->Text = L"menuStrip1";
			// 
			// CreateCarFormNav
			// 
			this->CreateCarFormNav->Name = L"CreateCarFormNav";
			this->CreateCarFormNav->Size = System::Drawing::Size(224, 24);
			this->CreateCarFormNav->Text = L"Поставить на учет владельца";
			this->CreateCarFormNav->Click += gcnew System::EventHandler(this, &MainForm::CreateCarFormNav_Click);
			// 
			// FilterBox
			// 
			this->FilterBox->Controls->Add(this->HaveNoInspectionThisYearFilterCheckBox);
			this->FilterBox->Controls->Add(this->ModelFilterTextBox);
			this->FilterBox->Controls->Add(this->ModelFilterCheckBox);
			this->FilterBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FilterBox->Location = System::Drawing::Point(75, 74);
			this->FilterBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->FilterBox->Name = L"FilterBox";
			this->FilterBox->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->FilterBox->Size = System::Drawing::Size(443, 169);
			this->FilterBox->TabIndex = 2;
			this->FilterBox->TabStop = false;
			this->FilterBox->Text = L"Фильтры";
			// 
			// HaveNoInspectionThisYearFilterCheckBox
			// 
			this->HaveNoInspectionThisYearFilterCheckBox->AutoSize = true;
			this->HaveNoInspectionThisYearFilterCheckBox->Location = System::Drawing::Point(9, 70);
			this->HaveNoInspectionThisYearFilterCheckBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->HaveNoInspectionThisYearFilterCheckBox->Name = L"HaveNoInspectionThisYearFilterCheckBox";
			this->HaveNoInspectionThisYearFilterCheckBox->Size = System::Drawing::Size(399, 29);
			this->HaveNoInspectionThisYearFilterCheckBox->TabIndex = 2;
			this->HaveNoInspectionThisYearFilterCheckBox->Text = L"Не прошедшие техосмотр в этом году";
			this->HaveNoInspectionThisYearFilterCheckBox->UseVisualStyleBackColor = true;
			// 
			// ModelFilterTextBox
			// 
			this->ModelFilterTextBox->Location = System::Drawing::Point(136, 30);
			this->ModelFilterTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ModelFilterTextBox->Name = L"ModelFilterTextBox";
			this->ModelFilterTextBox->Size = System::Drawing::Size(132, 30);
			this->ModelFilterTextBox->TabIndex = 1;
			this->ModelFilterTextBox->Text = L"Волга";
			// 
			// ModelFilterCheckBox
			// 
			this->ModelFilterCheckBox->AutoSize = true;
			this->ModelFilterCheckBox->Location = System::Drawing::Point(9, 32);
			this->ModelFilterCheckBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ModelFilterCheckBox->Name = L"ModelFilterCheckBox";
			this->ModelFilterCheckBox->Size = System::Drawing::Size(106, 29);
			this->ModelFilterCheckBox->TabIndex = 0;
			this->ModelFilterCheckBox->Text = L"Модель";
			this->ModelFilterCheckBox->UseVisualStyleBackColor = true;
			// 
			// ApplyFiltersButton
			// 
			this->ApplyFiltersButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ApplyFiltersButton->Location = System::Drawing::Point(452, 250);
			this->ApplyFiltersButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ApplyFiltersButton->Name = L"ApplyFiltersButton";
			this->ApplyFiltersButton->Size = System::Drawing::Size(155, 52);
			this->ApplyFiltersButton->TabIndex = 3;
			this->ApplyFiltersButton->Text = L"Применить";
			this->ApplyFiltersButton->UseVisualStyleBackColor = true;
			this->ApplyFiltersButton->Click += gcnew System::EventHandler(this, &MainForm::ApplyFiltersButton_Click);
			// 
			// OrderProvidersCheckBox
			// 
			this->OrderProvidersCheckBox->Controls->Add(this->SortByModelOrderProviderCheckBox);
			this->OrderProvidersCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->OrderProvidersCheckBox->Location = System::Drawing::Point(552, 74);
			this->OrderProvidersCheckBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->OrderProvidersCheckBox->Name = L"OrderProvidersCheckBox";
			this->OrderProvidersCheckBox->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->OrderProvidersCheckBox->Size = System::Drawing::Size(413, 169);
			this->OrderProvidersCheckBox->TabIndex = 3;
			this->OrderProvidersCheckBox->TabStop = false;
			this->OrderProvidersCheckBox->Text = L"Порядок";
			// 
			// SortByModelOrderProviderCheckBox
			// 
			this->SortByModelOrderProviderCheckBox->AutoSize = true;
			this->SortByModelOrderProviderCheckBox->Location = System::Drawing::Point(9, 39);
			this->SortByModelOrderProviderCheckBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->SortByModelOrderProviderCheckBox->Name = L"SortByModelOrderProviderCheckBox";
			this->SortByModelOrderProviderCheckBox->Size = System::Drawing::Size(363, 29);
			this->SortByModelOrderProviderCheckBox->TabIndex = 0;
			this->SortByModelOrderProviderCheckBox->Text = L"По модели в алфавитном порядке";
			this->SortByModelOrderProviderCheckBox->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1021, 694);
			this->Controls->Add(this->ApplyFiltersButton);
			this->Controls->Add(this->OrderProvidersCheckBox);
			this->Controls->Add(this->FilterBox);
			this->Controls->Add(this->CarTable);
			this->Controls->Add(this->Navigation);
			this->MainMenuStrip = this->Navigation;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CarTable))->EndInit();
			this->Navigation->ResumeLayout(false);
			this->Navigation->PerformLayout();
			this->FilterBox->ResumeLayout(false);
			this->FilterBox->PerformLayout();
			this->OrderProvidersCheckBox->ResumeLayout(false);
			this->OrderProvidersCheckBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
