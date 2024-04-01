#define _CRT_SECURE_NO_WARNINGS
#include "Volvo.h"
#include <cstring>
Volvo::Volvo()
{
	this->FuelCapacity = 75; // litres
	this->FuelConsumption = 9.5; // litres per 100 km
	this->AverageSpeed = 0; // km per hour
	this->name = new char[6];
	strcpy(this->name, "Volvo");
	this->name[5] = '\0';
}
double Volvo::GetFuelCapacity()
{
	return this->FuelCapacity;
}
double Volvo::GetFuelConsumption()
{
	return this->FuelConsumption;
}
int Volvo::GetAverageSpeed()
{
	return this->AverageSpeed;
}
void Volvo::SetAverageSpeed(Weather condition)
{
	if (condition == rainy)
		this->AverageSpeed = 63;
	else if (condition == snowy)
		this->AverageSpeed = 57;
	else this->AverageSpeed = 70;
}
void Volvo::DecFuelCap()
{
	if (this->FuelCapacity == 0) return;
	if (this->FuelCapacity - (this->FuelConsumption / 100.0) > 0)
		this->FuelCapacity -= (this->FuelConsumption / 100.0);
	else this->FuelCapacity = 0;
}
char* Volvo::GetName()
{
	return this->name;
}