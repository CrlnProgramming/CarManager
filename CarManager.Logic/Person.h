#pragma once

using namespace System;

namespace CarManager {
	namespace Logic {
		public ref class Person {
		public:
			Person(String^ FirstName, String^ SurName, String^ Address);

			String^ GetFirstName();
			void SetFirstName(String^);

			String^ GetSurName();
			void SetSurName(String^);

			String^ GetFullName();

			String^ GetAddress();
			void SetAddress(String^);

			String^ ToString() override;

		protected:
		private:
			String^ FirstName;
			String^ SurName;
			String^ Address;
		};
	}
}
