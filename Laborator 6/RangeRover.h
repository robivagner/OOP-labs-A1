#pragma once
#include "Car.h"
#include "Weather.h"
class RangeRover : public Car
{
public:
	RangeRover();
	~RangeRover() = default;
	double GetFuelCapacity();
	double GetFuelConsumption();
	int GetAverageSpeed();
	void SetAverageSpeed(Weather condition);
	void DecFuelCap();
	char* GetName();
};

