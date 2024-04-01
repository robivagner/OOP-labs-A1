#include "Circuit.h"
#include "Car.h"
#include <iostream>
Circuit::Circuit()
{
	this->cars = new Car * [0];
	this->numcars = 0;
	this->hours = new int[0];
	this->minutes = new int[0];
	this->seconds = new int[0];
}
Circuit::~Circuit()
{
	for (int i = 0; i < this->numcars; i++)
		delete[] this->cars[i];
	delete[] this->cars;
}
void Circuit::SetLength(int value)
{
	this->length = value;
}
void Circuit::SetWeather(Weather condition)
{
	this->condition = condition;
	for (int i = 0; i < this->numcars; i++)
		this->cars[i]->SetAverageSpeed(condition);
}
void Circuit::AddCar(Car* car)
{
	Car** tmp;
	tmp = new Car * [this->numcars + 1];
	for (int i = 0; i < this->numcars; i++)
		tmp[i] = this->cars[i];
	tmp[this->numcars] = car;
	tmp[this->numcars]->SetAverageSpeed(this->condition);
	delete[] this->cars;
	this->cars = tmp;

	int* tmph, * tmpm, * tmps;
	tmph = new int[this->numcars + 1];
	tmpm = new int[this->numcars + 1];
	tmps = new int[this->numcars + 1];

	for (int i = 0; i < this->numcars; i++)
	{
		tmph[i] = this->hours[i];
		tmpm[i] = this->minutes[i];
		tmps[i] = this->seconds[i];
	}

	delete[] this->hours;
	delete[] this->minutes;
	delete[] this->seconds;

	this->hours = tmph;
	this->hours[this->numcars] = 0;
	this->minutes = tmpm;
	this->minutes[this->numcars] = 0;
	this->seconds = tmps;
	this->seconds[this->numcars] = 0;

	this->numcars++;
}
void Circuit::Race()
{
	for (int i = 0; i < this->numcars - 1; i++)
		for (int j = i; j < this->numcars; j++)
			if (this->cars[i]->GetAverageSpeed() < this->cars[j]->GetAverageSpeed())
				std::swap(this->cars[i], this->cars[j]);

	for (int i = 0; i < this->length; i++)
		for (int j = 0; j < this->numcars; j++)
			this->cars[j]->DecFuelCap();

	int ultim = this->numcars;
	for (int i = 0; i < ultim; i++)
		if (this->cars[i]->GetFuelCapacity() == 0)
		{
			for (int j = i; j < ultim - 1; j++)
				std::swap(this->cars[j], this->cars[j + 1]);
			ultim--;
			i--;
		}

	for (int i = 0; i < ultim; i++)
	{
		double tmph = 0, tmpm = 0;

		tmph = double(this->length) / this->cars[i]->GetAverageSpeed();
		this->hours[i] = int(tmph);
		tmph = tmph - floor(tmph);

		if (tmph)
			tmpm = tmph * 60;
		if (tmpm)
			this->minutes[i] = int(tmpm);
		tmpm = tmpm - floor(tmpm);

		if (tmpm)
			this->seconds[i] = int(tmpm * 60);
	}
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < this->numcars; i++)
		if (this->cars[i]->GetFuelCapacity())
			printf("Place: %d Car: %s Time: %dh %dm %ds\n", i + 1, this->cars[i]->GetName(), this->hours[i], this->minutes[i], this->seconds[i]);
}
void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < this->numcars; i++)
		if (this->cars[i]->GetFuelCapacity() == 0)
			printf("Car: %s\n", this->cars[i]->GetName());
}