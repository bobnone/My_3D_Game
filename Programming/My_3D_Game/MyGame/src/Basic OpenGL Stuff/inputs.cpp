/*void joystick()
{
	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);
	cout << "Joystick/Gamepad status: " << present << endl;
	if (present == 1)
	{
		const char* name = glfwGetJoystickName(GLFW_JOYSTICK_1);
		cout << "Joystick Name: " << name << endl;
		int axesCount;
		const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
		cout << "Number of axes available: " << axesCount << endl;
		if (axesCount == 6)
		{
			cout << "Left Stick X Axis: " << axes[0] << endl;
			cout << "Left Stick Y Axis: " << axes[1] << endl;
			cout << "Right Stick X Axis: " << axes[2] << endl;
			cout << "Right Stick Y Axis: " << axes[3] << endl;
			cout << "Left Trigger/L2: " << axes[4] << endl;
			cout << "Right Trigger/R2: " << axes[5] << endl;
		}
		int buttonCount;
		const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
		if (GLFW_RELEASE == buttons[1])
		{
			cout << "X button pressed" << endl;
		}
		if (GLFW_PRESS == buttons[1])
		{
			cout << "X button pressed" << endl;
		}
		if (GLFW_REPEAT == buttons[1])
		{
			cout << "X button pressed" << endl;
		}
		//TODO: add more buttons and test code
	}
}*/