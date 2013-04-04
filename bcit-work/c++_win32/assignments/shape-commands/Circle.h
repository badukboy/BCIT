#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"

class Circle: public Shape
{
	public:

		// Constructor
		explicit Circle(std::istream& is);

		// Display
		virtual void draw() const;

		// Commands
		virtual void translate(const Point& delta);
		virtual void xreflect();
		virtual void yreflect();

		// Mutators
		bool setCentre(Point& centre);
		bool setRadius(int& radius);

	private:

		Point centre_;
		int radius_;
};

#endif
