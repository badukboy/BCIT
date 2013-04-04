#include "Circle.h"

using namespace std;

// Constructor
Circle::Circle(istream& is)
{
	is >> centre_ >> radius_;

	if(!is)
	{
		throw "Circle::Circle(const std::string&)";
	}
}

// Translate the Circle by 'delta'
void Circle::translate(const Point& delta)
{
	Point tempPoint(delta);

	int x;
	int y;

	int translateX;
	int translateY;

	x = centre_.getX();
	y = centre_.getY();

	translateX = tempPoint.getX();
	translateY = tempPoint.getY();

	Point newCentre(x + translateX, y + translateY);

	centre_ = newCentre;
}

// Reflect the Circle over the x-axis
void Circle::xreflect()
{
	int x;
	int y;

	x = centre_.getX();
	y = centre_.getY();

	Point newCentre(x, -y);

	centre_ = newCentre;
}

// Reflect the Circle over the y-axis
void Circle::yreflect()
{
	int x;
	int y;

	x = centre_.getX();
	y = centre_.getY();

	Point newCentre(-x, y);

	centre_ = newCentre;
}

// Mutator: centre_
bool Circle::setCentre(Point& centre)
{
	centre = centre_;

	return true;
}

// Mutator: radius_
bool Circle::setRadius(int& radius)
{
	radius = radius_;

	return true;
}

// Display
void Circle::draw() const
{
	cerr << "[C: " << centre_ << ", " << radius_ << "]" << endl;
}
