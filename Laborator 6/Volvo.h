#pragma once
#include "Car.h"
#include "Weather.h"
class Volvo : public Car
{
public:
	Volvo();
	~Volvo() = default;
	double GetFuelCapacity();
	double GetFuelConsumption();
	int GetAverageSpeed();
	void SetAverageSpeed(Weather condition);
	void DecFuelCap();
	char* GetName();
};

