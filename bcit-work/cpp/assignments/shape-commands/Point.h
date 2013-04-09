#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
	public:

		// Constructors
		explicit Point(int x = 0, int y = 0): x_(x), y_(y)
		{
		}

		// Accessors
		int getX();
		int getY();

		// Mutators
		bool setX(int& x);
		bool setY(int& y);

		/*
		Point& operator-(Point& delta)
		{
			return delta;
		}*/

		// Friends
		friend std::istream& operator>>(std::istream& is, Point& pt);
		friend std::ostream& operator<<(std::ostream& os, const Point& pt);
		friend Point& operator-(Point& delta);

	private:

		int x_;
		int y_;
};

// Inline overloaded istream operator
inline std::istream& operator>>(std::istream& is, Point& pt)
{
	char c1;
	char c2;
	char c3;
	int x;
	int y;

	is >> c1 >> x >> c2 >> y >> c3;

	if(is && c1 == '(' && c2 == ',' && c3 == ')')
	{
		pt.x_ = x;
		pt.y_ = y;
	}
	else
	{
		is.setstate(std::ios_base::failbit);
	}

	return is;
}

// Inline overloaded ostream operator
inline std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	os << '(' << pt.x_ << ',' << pt.y_ << ')';

	return os;
}

// Inline overloaded negation (-) operator
inline Point& operator-(Point& delta)
{
	int x;
	int y;

	int negateX;
	int negateY;

	x = delta.getX();
	y = delta.getY();

	negateX = -x;
	negateY = -y;

	delta.setX(negateX);
	delta.setY(negateY);

	return delta;
}

#endif
