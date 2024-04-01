#define _CRT_SECURE_NO_WARNINGS
#include "RangeRover.h"
#include <cstring>
RangeRover::RangeRover()
{
	this->FuelCapacity = 85; // litres
	this->FuelConsumption = 7.6; // litres per 100 km
	this->AverageSpeed = 0; // km per hour
	this->name = new char[11];
	strcpy(this->name, "RangeRover");
	this->name[10] = '\0';
}
double RangeRover::GetFuelCapacity()
{
	return this->FuelCapacity;
}
double RangeRover::GetFuelConsumption()
{
	return this->FuelConsumption;
}
int RangeRover::GetAverageSpeed()
{
	return this->AverageSpeed;
}
void RangeRover::SetAverageSpeed(Weather condition)
{
	if (condition == rainy)
		this->AverageSpeed = 60;
	else if (condition == snowy)
		this->AverageSpeed = 56;
	else this->AverageSpeed = 65;
}
void RangeRover::DecFuelCap()
{
	if (this->FuelCapacity == 0) return;
	if (this->FuelCapacity - (this->FuelConsumption / 100.0) > 0)
		this->FuelCapacity -= (this->FuelConsumption / 100.0);
	else this->FuelCapacity = 0;
}
char* RangeRover::GetName()
{
	return this->name;
}