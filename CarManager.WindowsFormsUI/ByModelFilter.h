#pragma once
#include"ICarFilter.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace CarManager::Logic;

namespace CarManagerWindowsFormsUI {
	namespace Filters {
		public ref class ByModelFilter:ICarFilter{
		public:
			ByModelFilter(CheckBox^ checkBox, TextBox^ model);
			virtual bool IsEnable();
			virtual array<Car^>^ Filter(array<Car^> ^);
		private:
			CheckBox^ checkBox;
			TextBox^ model;
		};
	}
}