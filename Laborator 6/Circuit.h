#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
	Car** cars;
	int length, numcars;
	int* hours, * minutes, * seconds;
	Weather condition;
public:
	Circuit();
	~Circuit();
	void SetLength(int value);
	void SetWeather(Weather condition);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

