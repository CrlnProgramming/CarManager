#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace CarManager::Logic;
namespace CarManagerWindowsFormsUI {
	namespace OrderProviders {
		public ref class QuicSorter {
		public:
			static void Sort(array<Car^>^,IComparer<Car^>^);
		private:
			static void Sort(array<Car^>^, int, int, IComparer<Car^>^);
		};
	}
}