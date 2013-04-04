#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"

class Shape
{
	public:

		// Destructor
		virtual ~Shape()
		{
		}

		// Display
		virtual void draw() const = 0;

		// Translate the shape by 'delta'
		virtual void translate(const Point& delta) = 0;

		// Reflect the shape over the x-axis
		virtual void xreflect() = 0;

		// Reflect the shape over the y-axis
		virtual void yreflect() = 0;
};

#endif
