#include <vector>
#include <sstream>
#include "DrawApp.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "Command.h"
#include "Point.h"

using namespace std;

// Constructor
DrawApp::DrawApp()
{
}

// Destructor
DrawApp::~DrawApp()
{
	for(vector<Shape*>::size_type i = 0; i < shapes_.size(); i++)
	{
		delete shapes_[i];
	}
}

// Loop to get user commands and execute them
void DrawApp::run()
{
	string input;
	Point translatePoint;
	Command* command;
	XReflectCommand xReflect;
	YReflectCommand yReflect;
	TranslateCommand trans;
	char commandType;
	int shapeNumber;
    vector<Command*>::size_type it = 0;

	// Draw the shapes on first iteration
	this -> draw();

	while(getline(cin, input))
	{
		cout << "> " << input << endl;

		istringstream iss(input);

		if(iss >> commandType)
		{	
			// Reflection over x-axis
			if(commandType == 'x')
			{
				if(iss >> shapeNumber)
				{
					// Error handling: invalid shape number
					if(shapeNumber > (int)shapes_.size())
					{
						continue;
					}

					// Create command
					xReflect = XReflectCommand(shapes_[shapeNumber - 1]);
				
					// Log command
					command = dynamic_cast<Command*>(&xReflect);
					history_.push_back(command);
					//cout << "+" << endl;

					if((int)it + 1 < (int)history_.size())
					{
						//cout << it << " is less than " << history_.size() << endl;

						for(int i = (int)it + 1; i <= (int)history_.size(); i++)
						{
							//cout << "Deleting back..." << endl;
							history_.pop_back();
						}
					}

					// Adjust undo/redo counters
					it++;
					//cout << it << endl;

					// Execute command
					xReflect.execute();

					// Redraw
					this -> draw();
				}
			}

			// Reflection over y-axis
			if(commandType == 'y')
			{
				if(iss >> shapeNumber)
				{
					// Error handling: invalid shape number
					if(shapeNumber > (int)shapes_.size())
					{
						continue;
					}

					// Create command
					yReflect = YReflectCommand(shapes_[shapeNumber - 1]);

					// Log command
					command = dynamic_cast<Command*>(&yReflect);
					history_.push_back(command);
					//cout << "+" << endl;

					if((int)it + 1 < (int)history_.size())
					{
						//cout << it << " is less than " << history_.size() << endl;

						for(int i = (int)it + 1; i <= (int)history_.size(); i++)
						{
							//cout << "Deleting back..." << endl;
							history_.pop_back();
						}
					}

					// Adjust undo/redo counters
					it++;
					//cout << it << endl;

					// Execute command
					yReflect.execute();

					// Redraw
					this -> draw();
				}
			}

			// Translation
			if(commandType == 't')
			{
				if(iss >> shapeNumber)
				{
					// Error handling: invalid shape number
					if(shapeNumber > (int)shapes_.size())
					{
						continue;
					}

					if(iss >> translatePoint)
					{
						// Create command
						trans = TranslateCommand(shapes_[shapeNumber - 1], translatePoint);

						// Log command
						command = dynamic_cast<Command*>(&trans);
						history_.push_back(command);
						//cout << "+" << endl;

						if((int)it + 1 < (int)history_.size())
						{
							//cout << it << " is less than " << history_.size() << endl;

							for(int i = (int)it + 1; i <= (int)history_.size(); i++)
							{
								//cout << "Deleting back..." << endl;
								history_.pop_back();
							}
						}

						// Adjust undo/redo counters
						it++;
						//cout << it << endl;

						// Execute command
						trans.execute();

						// Redraw
						this -> draw();
					}
				}
			}

			// Undo
			if(commandType == 'u')
			{	
				//cout << "Is " << (int)it - 1 << " >= 0?" << endl;

				if(((int)it - 1) >= 0)
				{
					//cout << "OK, got here" << endl;

					history_[it - 1] -> unexecute();

					it--;

					//cout << "New it: " << it << endl;

					this -> draw();
				}
			}

			// Redo
			if(commandType == 'r')
			{

				//cout << "Is " << (int)it + 1 << " <= " << history_.size() << "?" << endl;

				if(((int)it + 1) <= (int)history_.size())
				{
					//cout << "OK, got here" << endl;

					it++;

					history_[it - 1] -> execute();


					//cout << "New it: " << it << endl;
					this -> draw();
				}
			}

			// Error handling: invalid command type
			if(commandType != 'x' && commandType != 'y' && commandType != 't' && commandType != 'u' && commandType != 'r')
			{
				continue;
			}
		}
	}
}

// Adds a shape to vector
void DrawApp::addShape(Shape* s)
{
	shapes_.push_back(s);
}

// Undo command
bool DrawApp::undo()
{
	return true;
}

// Redo command
bool DrawApp::redo()
{
	return true;
}

// Draw all shapes
void DrawApp::draw() const
{
	int j = 1;

	for(vector<Shape*>::size_type i = 0; i < shapes_.size(); i++, j++)
	{
		cerr << j << ": ";
		shapes_[i] -> draw();
	}
}
