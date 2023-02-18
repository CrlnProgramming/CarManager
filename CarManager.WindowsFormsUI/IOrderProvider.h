#pragma once
using namespace System;
using namespace CarManager::Logic;
namespace CarManagerWindowsFormsUI {
	namespace OrderProviders {
		public interface class IOrderProvider
		{
			bool IsEnable();
			void ReOrder(array<Car^>^);
		};
	}
}