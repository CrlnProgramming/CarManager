#pragma once
#include"CamelCaseTextFormatter.h"
#include "TextFormater.h"

namespace CarManagerWindowsFormsUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CarManager::Logic;
	using namespace CarManagerWindowsFormsUI::Formaters;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для CreateCarForm
	/// </summary>
	public ref class EditCarForm : public System::Windows::Forms::Form
	{
	public:
		EditCarForm(CarService^ service, Car^ editedCar)
		{
			InitializeComponent();
			//
			CreateFormaters();
			//
			this->service = service;
			this->EditedCar = editedCar;
			CustomInitialize();

		}
#pragma region  CustomPart
	private:
		CarService^ service;
		Car^ EditedCar;
	private: System::Windows::Forms::TextBox^  ValidationErrorTextBox;

			 System::Collections::Generic::IEnumerable<ITextFormater^>^ Formaters;
			 void CreateFormaters();
			 void OnTextChangedFormatsApplier(System::Object ^sender, System::EventArgs ^e);

			 void CustomInitialize();

			 System::Void SubmitButton_Click(System::Object^  sender, System::EventArgs^  e);


#pragma endregion


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditCarForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  ModelLabel;
	protected:
	private: System::Windows::Forms::TextBox^  ModelTextBox;
	private: System::Windows::Forms::GroupBox^  NumberBox;
	private: System::Windows::Forms::TextBox^  LiteralCodeTextBox;
	private: System::Windows::Forms::Label^  LiteralCodeLabel;
	private: System::Windows::Forms::TextBox^  DigitalCodeTextBox;
	private: System::Windows::Forms::Label^  DigitalCodeLabel;
	private: System::Windows::Forms::TextBox^  RegionCodeTextBox;
	private: System::Windows::Forms::Label^  RegionCodeLabel;
	private: System::Windows::Forms::Label^  ColorLabel;
	private: System::Windows::Forms::TextBox^  ColorTextBox;

	private: System::Windows::Forms::GroupBox^  OwnerBox;

	private: System::Windows::Forms::TextBox^  SurNameTextBox;

	private: System::Windows::Forms::Label^  SurNameLabel;
	private: System::Windows::Forms::TextBox^  AddressesTextBox;

	private: System::Windows::Forms::Label^  AddressesLabel;

	private: System::Windows::Forms::TextBox^  NameTextBox;

	private: System::Windows::Forms::Label^  NameLabel;
	private: System::Windows::Forms::Label^  LastInspectionDateLabel;
	private: System::Windows::Forms::DateTimePicker^  LastInspectionDatePicker;
	private: System::Windows::Forms::Button^  SubmitButton;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ModelLabel = (gcnew System::Windows::Forms::Label());
			this->ModelTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumberBox = (gcnew System::Windows::Forms::GroupBox());
			this->LiteralCodeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LiteralCodeLabel = (gcnew System::Windows::Forms::Label());
			this->DigitalCodeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DigitalCodeLabel = (gcnew System::Windows::Forms::Label());
			this->RegionCodeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RegionCodeLabel = (gcnew System::Windows::Forms::Label());
			this->ColorLabel = (gcnew System::Windows::Forms::Label());
			this->ColorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OwnerBox = (gcnew System::Windows::Forms::GroupBox());
			this->AddressesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddressesLabel = (gcnew System::Windows::Forms::Label());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->SurNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SurNameLabel = (gcnew System::Windows::Forms::Label());
			this->LastInspectionDateLabel = (gcnew System::Windows::Forms::Label());
			this->LastInspectionDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->SubmitButton = (gcnew System::Windows::Forms::Button());
			this->ValidationErrorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumberBox->SuspendLayout();
			this->OwnerBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// ModelLabel
			// 
			this->ModelLabel->AutoSize = true;
			this->ModelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ModelLabel->Location = System::Drawing::Point(33, 25);
			this->ModelLabel->Name = L"ModelLabel";
			this->ModelLabel->Size = System::Drawing::Size(70, 20);
			this->ModelLabel->TabIndex = 0;
			this->ModelLabel->Text = L"Модель";
			// 
			// ModelTextBox
			// 
			this->ModelTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ModelTextBox->Location = System::Drawing::Point(37, 48);
			this->ModelTextBox->Name = L"ModelTextBox";
			this->ModelTextBox->Size = System::Drawing::Size(282, 26);
			this->ModelTextBox->TabIndex = 1;
			// 
			// NumberBox
			// 
			this->NumberBox->Controls->Add(this->LiteralCodeTextBox);
			this->NumberBox->Controls->Add(this->LiteralCodeLabel);
			this->NumberBox->Controls->Add(this->DigitalCodeTextBox);
			this->NumberBox->Controls->Add(this->DigitalCodeLabel);
			this->NumberBox->Controls->Add(this->RegionCodeTextBox);
			this->NumberBox->Controls->Add(this->RegionCodeLabel);
			this->NumberBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberBox->Location = System::Drawing::Point(37, 80);
			this->NumberBox->Name = L"NumberBox";
			this->NumberBox->Size = System::Drawing::Size(282, 199);
			this->NumberBox->TabIndex = 3;
			this->NumberBox->TabStop = false;
			this->NumberBox->Text = L"Номер машины";
			// 
			// LiteralCodeTextBox
			// 
			this->LiteralCodeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LiteralCodeTextBox->Location = System::Drawing::Point(20, 159);
			this->LiteralCodeTextBox->Name = L"LiteralCodeTextBox";
			this->LiteralCodeTextBox->Size = System::Drawing::Size(256, 26);
			this->LiteralCodeTextBox->TabIndex = 5;
			// 
			// LiteralCodeLabel
			// 
			this->LiteralCodeLabel->AutoSize = true;
			this->LiteralCodeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LiteralCodeLabel->Location = System::Drawing::Point(16, 136);
			this->LiteralCodeLabel->Name = L"LiteralCodeLabel";
			this->LiteralCodeLabel->Size = System::Drawing::Size(123, 20);
			this->LiteralCodeLabel->TabIndex = 4;
			this->LiteralCodeLabel->Text = L"Буквенный код";
			// 
			// DigitalCodeTextBox
			// 
			this->DigitalCodeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DigitalCodeTextBox->Location = System::Drawing::Point(20, 107);
			this->DigitalCodeTextBox->Name = L"DigitalCodeTextBox";
			this->DigitalCodeTextBox->Size = System::Drawing::Size(256, 26);
			this->DigitalCodeTextBox->TabIndex = 3;
			// 
			// DigitalCodeLabel
			// 
			this->DigitalCodeLabel->AutoSize = true;
			this->DigitalCodeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DigitalCodeLabel->Location = System::Drawing::Point(16, 84);
			this->DigitalCodeLabel->Name = L"DigitalCodeLabel";
			this->DigitalCodeLabel->Size = System::Drawing::Size(122, 20);
			this->DigitalCodeLabel->TabIndex = 2;
			this->DigitalCodeLabel->Text = L"Цифровой код";
			// 
			// RegionCodeTextBox
			// 
			this->RegionCodeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RegionCodeTextBox->Location = System::Drawing::Point(20, 55);
			this->RegionCodeTextBox->Name = L"RegionCodeTextBox";
			this->RegionCodeTextBox->Size = System::Drawing::Size(256, 26);
			this->RegionCodeTextBox->TabIndex = 1;
			// 
			// RegionCodeLabel
			// 
			this->RegionCodeLabel->AutoSize = true;
			this->RegionCodeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RegionCodeLabel->Location = System::Drawing::Point(16, 31);
			this->RegionCodeLabel->Name = L"RegionCodeLabel";
			this->RegionCodeLabel->Size = System::Drawing::Size(104, 20);
			this->RegionCodeLabel->TabIndex = 0;
			this->RegionCodeLabel->Text = L"Код региона";
			// 
			// ColorLabel
			// 
			this->ColorLabel->AutoSize = true;
			this->ColorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ColorLabel->Location = System::Drawing::Point(33, 282);
			this->ColorLabel->Name = L"ColorLabel";
			this->ColorLabel->Size = System::Drawing::Size(48, 20);
			this->ColorLabel->TabIndex = 4;
			this->ColorLabel->Text = L"Цвет";
			// 
			// ColorTextBox
			// 
			this->ColorTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ColorTextBox->Location = System::Drawing::Point(37, 305);
			this->ColorTextBox->Name = L"ColorTextBox";
			this->ColorTextBox->Size = System::Drawing::Size(282, 26);
			this->ColorTextBox->TabIndex = 5;
			// 
			// OwnerBox
			// 
			this->OwnerBox->Controls->Add(this->AddressesTextBox);
			this->OwnerBox->Controls->Add(this->AddressesLabel);
			this->OwnerBox->Controls->Add(this->NameTextBox);
			this->OwnerBox->Controls->Add(this->NameLabel);
			this->OwnerBox->Controls->Add(this->SurNameTextBox);
			this->OwnerBox->Controls->Add(this->SurNameLabel);
			this->OwnerBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OwnerBox->Location = System::Drawing::Point(325, 80);
			this->OwnerBox->Name = L"OwnerBox";
			this->OwnerBox->Size = System::Drawing::Size(282, 199);
			this->OwnerBox->TabIndex = 6;
			this->OwnerBox->TabStop = false;
			this->OwnerBox->Text = L"Сведения о владельце";
			// 
			// AddressesTextBox
			// 
			this->AddressesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddressesTextBox->Location = System::Drawing::Point(20, 162);
			this->AddressesTextBox->Name = L"AddressesTextBox";
			this->AddressesTextBox->Size = System::Drawing::Size(256, 26);
			this->AddressesTextBox->TabIndex = 5;
			// 
			// AddressesLabel
			// 
			this->AddressesLabel->AutoSize = true;
			this->AddressesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddressesLabel->Location = System::Drawing::Point(16, 139);
			this->AddressesLabel->Name = L"AddressesLabel";
			this->AddressesLabel->Size = System::Drawing::Size(57, 20);
			this->AddressesLabel->TabIndex = 4;
			this->AddressesLabel->Text = L"Адрес";
			// 
			// NameTextBox
			// 
			this->NameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameTextBox->Location = System::Drawing::Point(20, 110);
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(256, 26);
			this->NameTextBox->TabIndex = 3;
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameLabel->Location = System::Drawing::Point(16, 86);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(40, 20);
			this->NameLabel->TabIndex = 2;
			this->NameLabel->Text = L"Имя";
			// 
			// SurNameTextBox
			// 
			this->SurNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SurNameTextBox->Location = System::Drawing::Point(20, 57);
			this->SurNameTextBox->Name = L"SurNameTextBox";
			this->SurNameTextBox->Size = System::Drawing::Size(256, 26);
			this->SurNameTextBox->TabIndex = 1;
			// 
			// SurNameLabel
			// 
			this->SurNameLabel->AutoSize = true;
			this->SurNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SurNameLabel->Location = System::Drawing::Point(16, 34);
			this->SurNameLabel->Name = L"SurNameLabel";
			this->SurNameLabel->Size = System::Drawing::Size(81, 20);
			this->SurNameLabel->TabIndex = 0;
			this->SurNameLabel->Text = L"Фамилия";
			// 
			// LastInspectionDateLabel
			// 
			this->LastInspectionDateLabel->AutoSize = true;
			this->LastInspectionDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LastInspectionDateLabel->Location = System::Drawing::Point(321, 282);
			this->LastInspectionDateLabel->Name = L"LastInspectionDateLabel";
			this->LastInspectionDateLabel->Size = System::Drawing::Size(235, 20);
			this->LastInspectionDateLabel->TabIndex = 7;
			this->LastInspectionDateLabel->Text = L"Дата последнего техосмотра";
			// 
			// LastInspectionDatePicker
			// 
			this->LastInspectionDatePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LastInspectionDatePicker->Location = System::Drawing::Point(325, 305);
			this->LastInspectionDatePicker->Name = L"LastInspectionDatePicker";
			this->LastInspectionDatePicker->Size = System::Drawing::Size(282, 26);
			this->LastInspectionDatePicker->TabIndex = 8;
			// 
			// SubmitButton
			// 
			this->SubmitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SubmitButton->Location = System::Drawing::Point(266, 337);
			this->SubmitButton->Name = L"SubmitButton";
			this->SubmitButton->Size = System::Drawing::Size(100, 43);
			this->SubmitButton->TabIndex = 9;
			this->SubmitButton->Text = L"OK";
			this->SubmitButton->UseVisualStyleBackColor = true;
			this->SubmitButton->Click += gcnew System::EventHandler(this, &EditCarForm::SubmitButton_Click);
			// 
			// ValidationErrorTextBox
			// 
			this->ValidationErrorTextBox->BackColor = System::Drawing::SystemColors::Control;
			this->ValidationErrorTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ValidationErrorTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ValidationErrorTextBox->ForeColor = System::Drawing::Color::LightCoral;
			this->ValidationErrorTextBox->Location = System::Drawing::Point(345, 48);
			this->ValidationErrorTextBox->Name = L"ValidationErrorTextBox";
			this->ValidationErrorTextBox->Size = System::Drawing::Size(256, 19);
			this->ValidationErrorTextBox->TabIndex = 10;
			// 
			// CreateCarForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(640, 409);
			this->Controls->Add(this->ValidationErrorTextBox);
			this->Controls->Add(this->SubmitButton);
			this->Controls->Add(this->LastInspectionDatePicker);
			this->Controls->Add(this->LastInspectionDateLabel);
			this->Controls->Add(this->OwnerBox);
			this->Controls->Add(this->ColorTextBox);
			this->Controls->Add(this->ColorLabel);
			this->Controls->Add(this->NumberBox);
			this->Controls->Add(this->ModelTextBox);
			this->Controls->Add(this->ModelLabel);
			this->Name = L"EditCarForm";
			this->Text = L"EditCarForm";
			this->NumberBox->ResumeLayout(false);
			this->NumberBox->PerformLayout();
			this->OwnerBox->ResumeLayout(false);
			this->OwnerBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}
