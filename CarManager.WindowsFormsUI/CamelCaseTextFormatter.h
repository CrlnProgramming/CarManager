#pragma once
#include"TextFormater.h"
using namespace System;

namespace CarManagerWindowsFormsUI {
	namespace Formaters {
		public ref class CamelCaseTextFormatter : ITextFormater {
		public:
			virtual String^ Format(String^);
		};
	}
}