#include <iostream> //for using NULL
#include "ScalableVectorGraphics.h"

ScalableVectorGraphics::ScalableVectorGraphics()
{
	_rectangles = NULL;
	_size = 0;
}

ScalableVectorGraphics::ScalableVectorGraphics(const ScalableVectorGraphics& other)
{
	copy(other);
}

ScalableVectorGraphics::~ScalableVectorGraphics()
{
	releaseRectangles();
}

ScalableVectorGraphics& ScalableVectorGraphics::operator=(const ScalableVectorGraphics& other)
{
	if (this != &other)
	{
		releaseRectangles();
		copy(other);
	}

	return *this;
}

void ScalableVectorGraphics::addRectangle(const Rectangle& r)
{
	int newSize = _size + 1;
	Rectangle* newRectangles = new Rectangle[newSize];
	for (int i = 0; i < _size; ++i)
		newRectangles[i] = _rectangles[i];
	newRectangles[_size] = r;

	releaseRectangles();

	_size = newSize;
	_rectangles = newRectangles;
}

void ScalableVectorGraphics::addRectangle(Point pt1, Point pt2)
{
	addRectangle(Rectangle(pt1, pt2));
}

int ScalableVectorGraphics::size() const
{
	return _size;
}

const Rectangle& ScalableVectorGraphics::getRectangleAtIndex(int index) const
{
	return _rectangles[index];
}

int ScalableVectorGraphics::getBiggestAreaRectangleIndex() const
{
	int index = 0;

	double biggestArea = 0;
	for (int i = 0; i < _size; ++i)
	{
		double area = _rectangles[i].computeArea();
		if (area > biggestArea)
		{
			biggestArea = area;
			index = i;
		}
	}

	return index;
}


void ScalableVectorGraphics::copy(const ScalableVectorGraphics& other)
{
	_size = other.size();
	_rectangles = new Rectangle[_size];
	for (int i = 0; i < _size; ++i)
		_rectangles[i] = other.getRectangleAtIndex(i);
}

void ScalableVectorGraphics::releaseRectangles()
{
	if (_rectangles != NULL)
		delete[] _rectangles;
}