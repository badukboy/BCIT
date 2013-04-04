#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/* lab01.cpp */
int main()
{
	int width;
	int inputInt;
	double inputDouble;
	char conversionType;

	cout << setfill(' ');
	
	/* Format: {width}{d | o | x | X} {input int} */
	if(cin >> width >> conversionType >> inputInt)
	{
		if(width < 0)
		{	
			cout.setf(ios_base::left, ios_base::adjustfield);
		}
		else
		{
			cout.setf(ios_base::right, ios_base::adjustfield);
		}

		cout.width(abs(width));
		
		/* 
		 *	Determine conversion type used. If period found instead, continue
		 *	with precision, followed by a new set of possible conversion types
		 *	and a double.
		 */
		switch(conversionType)
		{
			case '.':
				cout << setprecision(inputInt);

				/* Format: {width}.{precision (taken from input int)}{f | e | E} {input double} */
				if(cin >> conversionType >> inputDouble)
				{
					switch(conversionType)
					{
						case 'f':
							cout << fixed << inputDouble << "|" << endl;
							break;
						
						case 'e':
							cout << scientific << inputDouble << "|" << endl;
							break;
							
						case 'E':	
							cout << scientific << uppercase << inputDouble << "|" << endl;
							break;
					}
				}
				
				break;
				
			case 'd':
				cout << fixed << noshowpos << inputInt << "|" << endl;
				break;
				
			case 'o':
				cout << oct << noshowpos << inputInt << "|" << endl;
				break;
				
			case 'x':
				cout << hex << noshowpos << inputInt << "|" << endl;
				break;
				
			case 'X':
				cout << hex << noshowpos << uppercase << inputInt << "|" << endl;
				break;
		}
	}
}
