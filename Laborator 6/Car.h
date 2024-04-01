#pragma once
#include "Weather.h"
class Car
{
public:
	virtual ~Car() = default;
	virtual double GetFuelCapacity() = 0;
	virtual double GetFuelConsumption() = 0;
	virtual int GetAverageSpeed() = 0;
	virtual void SetAverageSpeed(Weather condition) = 0;
	virtual void DecFuelCap() = 0;
	virtual char* GetName() = 0;
protected:
	double FuelCapacity, FuelConsumption;
	int AverageSpeed;
	char* name;
};

