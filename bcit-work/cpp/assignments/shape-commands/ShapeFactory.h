#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"

class ShapeFactory
{
	public:

		// Constructor
		ShapeFactory(std::istream& is): in_(&is)
		{
		}

		// Create shape
		Shape* create()
		{
			std::string type;

			if(!(*in_ >> type))
			{
				return 0;
			}

			if(type == "C")
			{
				return new Circle(*in_);
			}

			if(type == "T")
			{
				return new Triangle(*in_);
			}

			// In the case that a command is accidentaly read
			(*in_).unget();

			return 0;
		}

	private:

		std::istream *in_;
};

#endif
