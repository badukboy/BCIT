#ifndef DRAWAPP_H
#define DRAWAPP_H
#include <vector>
#include "Shape.h"
#include "Command.h"

using namespace std;

// NOTE: May need to include additional headers
class DrawApp
{
	public:

		// Constructor
		DrawApp();

		// Destructor
		~DrawApp();

		// Loop to get user commands & execute them
		void run();

		// Add a shape to vector
		void addShape(Shape* s);

		// Undo action
		bool undo();

		// Redo action
		bool redo();

	private:

		// Draw all shapes
		void draw() const;

		// Vector of shapes
		vector<Shape*> shapes_;

		// Action history vector
		vector<Command*> history_;
};

#endif
