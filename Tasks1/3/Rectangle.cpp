#include <cmath>
#include "Rectangle.h"

Rectangle::Rectangle() : _pt1(Point()), _pt2(Point()) 
{}

Rectangle::Rectangle(Point pt1, Point pt2) : _pt1(pt1), _pt2(pt2) 
{}

double Rectangle::width() const
{ 
	return std::abs(_pt1.x - _pt2.x);
}

double Rectangle::height() const
{
	return std::abs(_pt1.y - _pt2.y);
}

double Rectangle::computeArea() const 
{ 
	return width() * height(); 
}