#pragma once
#include "Point.h"

class Rectangle
{
public:
	Rectangle();
	Rectangle(Point pt1, Point pt2);

	Point getPt1() const { return _pt1; }
	Point getPt2() const { return _pt2; }

	double width() const;
	double height() const;
	double computeArea() const;

private:
	Point _pt1;
	Point _pt2;
};
