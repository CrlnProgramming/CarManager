#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace CarManager::Logic;
namespace CarManagerWindowsFormsUI {
	namespace Filters {
		public interface class ICarFilter
		{
			bool IsEnable();
			array<Car^>^ Filter(array<Car^>^);
		};
	}
}