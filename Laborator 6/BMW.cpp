#define _CRT_SECURE_NO_WARNINGS
#include "BMW.h"
#include <cstring>
BMW::BMW()
{
	this->FuelCapacity = 60; // litres
	this->FuelConsumption = 7.2; // litres per 100 km
	this->AverageSpeed = 0; // km per hour
	this->name = new char[4];
	strcpy(this->name, "BMW");
	this->name[3] = '\0';
}
double BMW::GetFuelCapacity()
{
	return this->FuelCapacity;
}
double BMW::GetFuelConsumption()
{
	return this->FuelConsumption;
}
int BMW::GetAverageSpeed()
{
	return this->AverageSpeed;
}
void BMW::SetAverageSpeed(Weather condition)
{
	if (condition == rainy)
		this->AverageSpeed = 83;
	else if (condition == snowy)
		this->AverageSpeed = 75;
	else this->AverageSpeed = 95;
}
void BMW::DecFuelCap()
{
	if (this->FuelCapacity == 0) return;
	if (this->FuelCapacity - (this->FuelConsumption / 100.0) > 0)
		this->FuelCapacity -= (this->FuelConsumption / 100.0);
	else this->FuelCapacity = 0;
}
char* BMW::GetName()
{
	return this->name;
}