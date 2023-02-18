#include "CamelCaseTextFormatter.h"

String ^ CarManagerWindowsFormsUI::Formaters::CamelCaseTextFormatter::Format(String ^text)
{
	if (text == nullptr) {
		return text;
	}

	if (text->Length >= 1) {
		String^ first = text->Substring(0, 1)->ToUpper();
		text = text->Remove(0, 1)->ToLower()->Insert(0, first);
	}

	return text;
}
