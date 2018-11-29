#ifndef CALLBACKS_H
#define CALLBACKs_H

#include "../display.h"
#include "inputs.h"
#include "../settings.h"

class Callbacks
{
public:
	// Init metod
	Callbacks(Display* display, Inputs* inputs);
	// Wrapper for error related callbacks (must be called before Init(), as it is use during Init())
	void errorCallbacks();
	// Wrapper for display(window+context) related callbacks
	void displayCallbacks();
	// Wrapper for monitor related callbacks
	void monitorCallbacks();
	// Wrapper for input related callbacks
	void inputCallbacks();
protected:
private:
	Display* display;
};
#endif