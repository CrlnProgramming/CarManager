#include "stdafx.h"
#include "CarNumber.h"

using namespace CarManager::Logic;

CarNumber::CarNumber(String ^ regionCode, String ^ digitalCode, String ^ literalCode)
{
	SetDigitalCode(digitalCode);
	SetRegionCode(regionCode);
	SetLiteralCode(literalCode);
}

String ^ CarNumber::GetRegionCode()
{
	return RegionCode;
}

void CarNumber::SetRegionCode(String^ regionCode)
{
	if (String::IsNullOrWhiteSpace(regionCode))
	{
		throw gcnew ArgumentException("Invalid RegionCode");
	}
	this->RegionCode = regionCode;
}

String ^ CarNumber::GetDigitalCode()
{
	return DigitalCode;
}

void CarNumber::SetDigitalCode(String^ digitalCode)
{
	if (String::IsNullOrWhiteSpace(digitalCode))
	{
		throw gcnew ArgumentException("Invalid DigitalCode");
	}
	this->DigitalCode = digitalCode;
}

String ^ CarNumber::GetLiteralCode()
{
	return LiteralCode;
}

void CarNumber::SetLiteralCode(String^ literalCode)
{
	if (String::IsNullOrWhiteSpace(literalCode))
	{
		throw gcnew ArgumentException("Invalid LiteralCode");
	}
	this->LiteralCode = literalCode;
}

String ^ CarNumber::GetFullCarNumber()
{
	return String::Format("{0} {1} {2}", RegionCode, DigitalCode, LiteralCode);
}

String ^ CarNumber::ToString()
{
	return this->GetFullCarNumber();
}
