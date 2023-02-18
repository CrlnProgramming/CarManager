#pragma once
#include"CarNumber.h"
#include"Person.h"

using namespace System;

namespace CarManager{
	namespace Logic {
		public ref class Car
		{
		public:
			Car(String^ model, CarNumber^ carNumber, String^ color, Person^ owner, DateTime lastInspectionDate);

			property String^ Model {
				String^ get();
				void set(String^);
			};

			property CarNumber^ Number {
				CarNumber^ get();
				void set(CarNumber^);
			};

			property String^ Color {
				String^ get();
				void set(String^);
			};

			property Person^ Owner {
				Person^ get();
				void set(Person^);
			};

			property DateTime LastInspectionDate {
				DateTime get();
				void set(DateTime);
			};

			String^ ToString() override;

		private:
			String^ _Model;
			CarNumber^ _Number;
			String^ _Color;
			Person^ _Owner;
			DateTime _LastInspectionDate;
		};

	}
}