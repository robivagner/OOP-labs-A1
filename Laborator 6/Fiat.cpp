#define _CRT_SECURE_NO_WARNINGS
#include "Fiat.h"
#include <cstring>
Fiat::Fiat()
{
	this->FuelCapacity = 60; // litres
	this->FuelConsumption = 9.1; // litres per 100 km
	this->AverageSpeed = 0; // km per hour
	this->name = new char[5];
	strcpy(this->name, "Fiat");
	this->name[4] = '\0';
}
double Fiat::GetFuelCapacity()
{
	return this->FuelCapacity;
}
double Fiat::GetFuelConsumption()
{
	return this->FuelConsumption;
}
int Fiat::GetAverageSpeed()
{
	return this->AverageSpeed;
}
void Fiat::SetAverageSpeed(Weather condition)
{
	if (condition == rainy)
		this->AverageSpeed = 59;
	else if (condition == snowy)
		this->AverageSpeed = 44;
	else this->AverageSpeed = 60;
}
void Fiat::DecFuelCap()
{
	if (this->FuelCapacity == 0) return;
	if (this->FuelCapacity - (this->FuelConsumption / 100.0) > 0)
		this->FuelCapacity -= (this->FuelConsumption / 100.0);
	else this->FuelCapacity = 0;
}
char* Fiat::GetName()
{
	return this->name;
}