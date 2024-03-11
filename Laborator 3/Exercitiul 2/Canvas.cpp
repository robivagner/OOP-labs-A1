#include "Canvas.h"
#include <iostream>
#include <cmath>
Canvas::Canvas(int a, int b)
{
	this->width = a;
	this->height = b;
	this->c = new char* [this->height];
	for (int i = 0; i < this->height; i++)
	{
		this->c[i] = new char[this->width];
		for (int j = 0; j < this->width; j++)
			this->c[i][j] = ' ';
	}
}
Canvas::~Canvas()
{
	for (int i = 0; i < this->height; i++)
		delete[] this->c[i];
	delete[] this->c;
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; ++i) {
		for (int j = 0; j < this->width; ++j) {
			int dx = i - x;
			int dy = j - y;
			double distance = sqrt(dx * dx + dy * dy);

			if (abs(distance - ray) < 0.4)
			{
				this->c[i][j] = ch;
			}
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; ++i) {
		for (int j = 0; j < this->width; ++j) {
			int dx = i - x;
			int dy = j - y;
			double distance = sqrt(dx * dx + dy * dy);

			if (distance <= ray)
			{
				this->c[i][j] = ch;
			}
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		if (i >= 0 && i < this->height)
		{
			if (left >= 0 && left < this->width)
				this->c[i][left] = ch;
			if (right >= 0 && right < this->width)
				this->c[i][right] = ch;
		}
	for (int j = left; j <= right; j++)
		if (j >= 0 && j < this->width)
		{
			if (top >= 0 && top < this->height)
				this->c[top][j] = ch;
			if (bottom >= 0 && bottom < this->height)
				this->c[bottom][j] = ch;
		}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top + 1; i < bottom; i++)
		for (int j = left + 1; j < right; j++)
			if (i >= 0 && i < this->height && j >= 0 && j < this->width)
				this->c[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < this->width && y >= 0 && y < this->height)
		this->c[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) 
{
	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int err = dx + dy, e2;

	while (true) {
		this->c[y1][x1] = ch;
		if (x1 == x2 && y1 == y2) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x1 += sx; }
		if (e2 <= dx) { err += dx; y1 += sy; }
	}
}
void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			printf("%c ", c[i][j]);
		printf("\n");
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->c[i][j] = ' ';
}