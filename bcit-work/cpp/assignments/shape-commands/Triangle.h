#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"

class Triangle: public Shape
{
	public:

		// Constructor
		explicit Triangle(std::istream& is);

		// Display
		virtual void draw() const;

		// Commands
		virtual void translate(const Point& delta);
		virtual void xreflect();
		virtual void yreflect();

		// Mutator
		bool setPoints(Point& v1, Point& v2, Point& v3);

	private:

		Point v1_;
		Point v2_;
		Point v3_;
};

#endif
