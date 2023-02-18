#include "stdafx.h"
#include "Person.h"

using namespace CarManager::Logic;

Person::Person(String ^ firstName, String ^ surName, String ^ address)
{
	SetFirstName(firstName);
	SetSurName(surName);
	SetAddress(address);
}

String ^ Person::GetFirstName()
{
	return this->FirstName;
}

void Person::SetFirstName(String ^ firstName)
{
	if (String::IsNullOrWhiteSpace(firstName)) {
		throw gcnew ArgumentException("Invalid firstName");
	}

	this->FirstName = firstName;
}

String ^ Person::GetSurName()
{
	return this->SurName;
}

void Person::SetSurName(String ^ surName)
{
	if (String::IsNullOrWhiteSpace(surName)) {
		throw gcnew ArgumentException("Invalid surName");
	}

	this->SurName = surName;
}

String ^ Person::GetFullName()
{
	return String::Format("{0} {1}", SurName, FirstName);
}

String ^ Person::GetAddress()
{
	return this->Address;
}

void Person::SetAddress(String^ address)
{
	if (String::IsNullOrWhiteSpace(address)) {
		throw gcnew ArgumentException("Invalid address");
	}

	this->Address = address;
}

String ^ Person::ToString()
{
	return String::Format("{0},{1}", this->GetFullName(), this->Address);
}
