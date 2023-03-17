#pragma once
#include "Rectangle.h"

class ScalableVectorGraphics
{
public:
	ScalableVectorGraphics();
	ScalableVectorGraphics(const ScalableVectorGraphics& other);
	~ScalableVectorGraphics();
	ScalableVectorGraphics& operator=(const ScalableVectorGraphics& other);

	void addRectangle(const Rectangle& r);
	void addRectangle(Point pt1, Point pt2);

	int size() const;
	const Rectangle& getRectangleAtIndex(int index) const;
	int getBiggestAreaRectangleIndex() const;

private:
	Rectangle* _rectangles;
	int _size;

	void copy(const ScalableVectorGraphics& other);
	void releaseRectangles();
};