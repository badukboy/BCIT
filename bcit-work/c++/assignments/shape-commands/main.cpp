#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "ShapeFactory.h"
#include "Shape.h"
#include "Command.h"
#include "DrawApp.h"

using namespace std;

// MAIN
int main(int argc, char* argv[])
{
	// Creating shapes from this file stream
	fstream dataFile;

	// Error handling: invalid command line arguments
	if(argc != 2)
	{
		cout << "Invalid argument amount." << endl;

		return 1;
	}
	else
	{
		// Open file
		dataFile.open(argv[1]);

		// Error handling: file opening
		if(!dataFile.is_open())
		{
			cerr << "Error opening file." << endl;

			return 1;
		}
	}

	DrawApp drawApp;
	Shape* s;
	ShapeFactory sf(dataFile);

	// Creating and adding shapes
	while((s = sf.create()) != 0)
	{
		drawApp.addShape(s);
	}

	drawApp.run();
}
