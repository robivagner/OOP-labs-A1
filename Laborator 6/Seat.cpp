#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include <cstring>
Seat::Seat()
{
	this->FuelCapacity = 70; // litres
	this->FuelConsumption = 8.3; // litres per 100 km
	this->AverageSpeed = 0; // km per hour
	this->name = new char[5];
	strcpy(this->name, "Seat");
	this->name[4] = '\0';
}
double Seat::GetFuelCapacity()
{
	return this->FuelCapacity;
}
double Seat::GetFuelConsumption()
{
	return this->FuelConsumption;
}
int Seat::GetAverageSpeed()
{
	return this->AverageSpeed;
}
void Seat::SetAverageSpeed(Weather condition)
{
	if (condition == rainy)
		this->AverageSpeed = 58;
	else if (condition == snowy)
		this->AverageSpeed = 53;
	else this->AverageSpeed = 68;
}
void Seat::DecFuelCap()
{
	if (this->FuelCapacity == 0) return;
	if (this->FuelCapacity - (this->FuelConsumption / 100.0) > 0)
		this->FuelCapacity -= (this->FuelConsumption / 100.0);
	else this->FuelCapacity = 0;
}
char* Seat::GetName()
{
	return this->name;
}