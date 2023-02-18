#pragma once
#include"IOrderProvider.h"

using namespace System;
using namespace CarManager::Logic;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;

namespace CarManagerWindowsFormsUI {
	namespace OrderProviders {
		public ref class SortByModelOrderProvider:IOrderProvider
		{
		public:
			SortByModelOrderProvider(CheckBox^ checkbox);
			virtual bool IsEnable();
			virtual void ReOrder(array<Car^>^);
		private:
			CheckBox^ checkBox;
			System::Collections::Generic::IComparer<Car^>^ comparer;
		};
	}
}