#pragma once
#include "Car.h"
#include "Weather.h"
class BMW : public Car
{
public:
	BMW();
	~BMW() = default;
	double GetFuelCapacity();
	double GetFuelConsumption();
	int GetAverageSpeed();
	void SetAverageSpeed(Weather condition);
	void DecFuelCap();
	char* GetName();
};

