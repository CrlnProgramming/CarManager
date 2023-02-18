#include "stdafx.h"
#include "CarService.h"

using namespace CarManager::Logic;


CarService::CarService()
{
	this->Cars = gcnew List<Car^>();
}

void CarService::AddCar(Car ^ car)
{
	NullValidation(car);
	this->Cars->Add(car);
	OnUpdate();
}

void CarService::RemoveCar(Car ^ car)
{
	NullValidation(car);
	this->Cars->Remove(car);
	OnUpdate();
}

array<Car^>^ CarService::GetCars()
{
	return this->Cars->ToArray();
}

void CarService::NullValidation(Object^ obj)
{
	if (obj == nullptr) {
		throw gcnew ArgumentException("Argument can't be null");
	}
}
