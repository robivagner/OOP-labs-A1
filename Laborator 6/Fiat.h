#pragma once
#include "Car.h"
#include "Weather.h"
class Fiat : public Car
{
public:
	Fiat();
	~Fiat() = default;
	double GetFuelCapacity();
	double GetFuelConsumption();
	int GetAverageSpeed();
	void SetAverageSpeed(Weather condition);
	void DecFuelCap();
	char* GetName();
};

