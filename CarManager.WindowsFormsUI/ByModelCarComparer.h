#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace CarManager::Logic;
namespace CarManagerWindowsFormsUI {
	namespace OrderProviders {
		public ref class ByModelCarComparer :IComparer<Car^>
		{
		public:
			virtual int Compare(Car^, Car^);
		};
	}
}