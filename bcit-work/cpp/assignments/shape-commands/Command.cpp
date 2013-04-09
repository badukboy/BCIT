#include "Command.h"
#include "Circle.h"
#include "Point.h"

using namespace std;

// Execution of translation
void TranslateCommand::execute()
{
	//cout << "Executing translation..." << endl;

	shape_ -> translate(delta_);
}

// Unexecution of translation
void TranslateCommand::unexecute()
{
	//cout << "Undoing translation..." << endl;

	shape_ -> translate(-delta_);
}

// Execution of x-axis reflection
void XReflectCommand::execute()
{
	//cout << "Executing x-reflection..." << endl;

	shape_ -> xreflect();
}

// Unexecution of x-axis reflection
void XReflectCommand::unexecute()
{
	//cout << "Undoing x-reflection..." << endl;

	shape_ -> xreflect();
}

// Execution of y-axis reflection
void YReflectCommand::execute()
{
	//cout << "Executing y-reflection..." << endl;

	shape_ -> yreflect();
}

// Unexecution of y-axis reflection
void YReflectCommand::unexecute()
{
	//cout << "Undoing y-reflection..." << endl;

	shape_ -> yreflect();
}
