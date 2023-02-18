#include "stdafx.h"
#include "Car.h"
#include "CarNumber.h"

using namespace CarManager::Logic;

Car::Car(String ^ model, CarNumber ^ carNumber, String ^ color, Person ^ owner, DateTime lastInspectionDate)
{
	this->Model = model;
	this->Number = carNumber;
	this->Color = color;
	this->Owner = owner;
	this->LastInspectionDate = lastInspectionDate;
}

String^ Car::Model::get(){
	return this->_Model;
}
void Car::Model::set(String^ model) {
	if (String::IsNullOrEmpty(model)) {
		throw gcnew ArgumentException("Invalid model");
	}
	this->_Model = model;
}

CarNumber^ Car::Number::get() {
	return this->_Number;
}
void Car::Number::set(CarNumber^ number) {
	if (number == nullptr) {
		throw gcnew ArgumentException("Invalid number");
	}
	this->_Number = number;
}

String^ Car::Color::get() {
	return this->_Color;
}
void Car::Color::set(String^ color) {
	if (String::IsNullOrWhiteSpace(color)) {
		throw gcnew ArgumentException("Invalid color");
	}
	this->_Color = color;
}

Person^ Car::Owner::get() {
	return this->_Owner;
}
void Car::Owner::set(Person^ owner) {
	if (owner == nullptr) {
		throw gcnew ArgumentException("Invalid owner");
	}
	this->_Owner = owner;
}

DateTime Car::LastInspectionDate::get() {
	return this->_LastInspectionDate;
}
void Car::LastInspectionDate::set(DateTime date) {
	this->_LastInspectionDate = date;
}

String ^ Car::ToString()
{
	return String::Format("{0},{1},{2},{3},{4}", _Model, _Number, _Color, _Owner, _LastInspectionDate);
}
