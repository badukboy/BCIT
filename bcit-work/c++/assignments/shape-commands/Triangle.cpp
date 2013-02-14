#include "Triangle.h"

using namespace std;

// Constructor
Triangle::Triangle(istream& is)
{
	is >> v1_ >> v2_ >> v3_;

	if(!is)
	{
		throw "Triangle::Triangle(const std::string&)";
	}
}

// Translate the Triangle by 'delta'
void Triangle::translate(const Point& delta)
{
	Point tempPoint(delta);

	int x1;
	int x2;
	int x3;
	int y1;
	int y2;
	int y3;

	int translateX;
	int translateY;

	x1 = v1_.getX();
	x2 = v2_.getX();
	x3 = v3_.getX();
	y1 = v1_.getY();
	y2 = v2_.getY();
	y3 = v3_.getY();

	translateX = tempPoint.getX();
	translateY = tempPoint.getY();

	Point newV1(x1 + translateX, y1 + translateY);
	Point newV2(x2 + translateX, y2 + translateY);
	Point newV3(x3 + translateX, y3 + translateY);

	v1_ = newV1;
	v2_ = newV2;
	v3_ = newV3;
}

// Reflect the Triangle over the x-axis
void Triangle::xreflect()
{
	int x1;
	int x2;
	int x3;
	int y1;
	int y2;
	int y3;

	x1 = v1_.getX();
	x2 = v2_.getX();
	x3 = v3_.getX();
	y1 = v1_.getY();
	y2 = v2_.getY();
	y3 = v3_.getY();

	Point newV1(x1, -y1);
	Point newV2(x2, -y2);
	Point newV3(x3, -y3);

	v1_ = newV1;
	v2_ = newV2;
	v3_ = newV3;
}

// Reflect the Triangle over the y-axis
void Triangle::yreflect()
{
	int x1;
	int x2;
	int x3;
	int y1;
	int y2;
	int y3;

	x1 = v1_.getX();
	x2 = v2_.getX();
	x3 = v3_.getX();
	y1 = v1_.getY();
	y2 = v2_.getY();
	y3 = v3_.getY();

	Point newV1(-x1, y1);
	Point newV2(-x2, y2);
	Point newV3(-x3, y3);

	v1_ = newV1;
	v2_ = newV2;
	v3_ = newV3;
}

// Mutator: v1_, v2_, v3_
bool Triangle::setPoints(Point& v1, Point& v2, Point& v3)
{
	v1_ = v1;
	v2_ = v2;
	v3_ = v3;

	return true;
}

// Display
void Triangle::draw() const
{
	cerr << "[T: " << v1_ << ", " << v2_ << ", " << v3_ << "]" << endl;
}
