#include "Point.h"

using namespace std;

// Accessor: x_
int Point::getX()
{
	return x_;
}

// Accessor: y_
int Point::getY()
{
	return y_;
}

// Mutator: x_
bool Point::setX(int& x)
{
	x_ = x;

	return true;
}

// Mutator: y_
bool Point::setY(int& y)
{
	y_ = y;
	
	return true;
}
