#ifndef COMMAND_H
#define COMMAND_H
#include "Shape.h"

class Command
{
	public:

		// Destructor
		virtual ~Command()
		{
		}

		// Execute command
		virtual void execute() = 0;

		// Unexecute command
		virtual void unexecute() = 0;
};

class TranslateCommand: public Command
{
	public:
	
		// Constructor
		explicit TranslateCommand(Shape* s = 0, const Point& delta = Point()):
			shape_(s), delta_(delta)
		{
		}

		// Execute command
		virtual void execute();

		// Unexecute command
		virtual void unexecute();

	private:

		Shape* shape_;
		Point delta_;
};

class XReflectCommand: public Command
{
	public:

		// Constructor
		explicit XReflectCommand(Shape* s = 0): shape_(s)
		{
		}

		// Execute command
		virtual void execute();

		// Unexecute command
		virtual void unexecute();

	private:

		Shape* shape_;
};

class YReflectCommand: public Command
{
	public:

		// Constructor
		explicit YReflectCommand(Shape* s = 0): shape_(s)
		{
		}

		// Execute command
		virtual void execute();

		// Unexecute command
		virtual void unexecute();
	
	private:

		Shape* shape_;
};

#endif
