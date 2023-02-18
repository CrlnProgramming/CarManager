#pragma once
#include"Car.h"

using namespace System;
using namespace System::Collections::Generic;

namespace CarManager {
	namespace Logic {
		public ref class CarService {
		public:
			event EventHandler^ Update;

			CarService();

			void AddCar(Car^);
			void RemoveCar(Car^);
			array<Car^>^ GetCars();

		protected:
			void OnUpdate() {
				Update(this, nullptr);
			}
		private:
			List<Car^>^ Cars;

			void NullValidation(Object^);

		};
	}
}