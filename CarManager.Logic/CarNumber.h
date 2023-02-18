#pragma once

using namespace System;

namespace CarManager {
	namespace Logic {
		public ref class CarNumber {
		public:
			CarNumber(String^ regionCode, String^ digitalCode, String^ literalCode);

			String^ GetRegionCode();
			void SetRegionCode(String^);

			String^ GetDigitalCode();
			void SetDigitalCode(String^);

			String^ GetLiteralCode();
			void SetLiteralCode(String^);

			String^ GetFullCarNumber();

			String^ ToString() override;

		protected:
		private:
			String^ RegionCode;
			String^ DigitalCode;
			String^ LiteralCode;
		};
	}
}
