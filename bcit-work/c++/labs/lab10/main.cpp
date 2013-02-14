#include <iostream>
#include <ostream>
#include <istream>
#include <sstream>
#include "Clock.h"

using namespace std;

// DRIVER
int main()
{
	Clock c1(2, 9);
	Clock c2("23:59");
	Clock c3(0, 0);
	Clock c4("12:00");

	cout << c1 << endl;		// 02:09
	cout << c2 << endl;		// 23:59
	cout << c3 << endl;		// 00:00
	cout << c4 << endl;		// 12:00

	c1.print();				// 02:09AM
	c2.print();				// 11:59PM
	c3.print();				// 12:00AM
	c4.print();				// 12:00PM

	c1++.print();			// 02:09PM
	c1.print();				// 02:10PM

	(++c2).print();			// 12:00AM

	cout << (c3 == c2) << endl;		// 00:00 == 00:00
	cout << (c1 < c4) << endl;		// 02:10 < 12:00
	cout << (c3 <= c2) << endl;		// 00:00 <= 00:00
	cout << (c4 >= c2) << endl;		// 12:00 >= 00:00 
	cout << (c1 > c2) << endl;		// 02:10 > 00:00
}
