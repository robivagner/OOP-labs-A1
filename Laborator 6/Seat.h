#pragma once
#include "Car.h"
#include "Weather.h"
class Seat : public Car
{
public:
	Seat();
	~Seat() = default;
	double GetFuelCapacity();
	double GetFuelConsumption();
	int GetAverageSpeed();
	void SetAverageSpeed(Weather condition);
	void DecFuelCap();
	char* GetName();
};

