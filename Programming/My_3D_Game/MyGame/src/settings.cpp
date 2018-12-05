#include "Settings.h"

/*ifstream reader("file1.txt");
int a, b, c;
string d, e;
if (reader.is_open())
{
	reader >> a >> b;
	reader >> c;
	getline(reader, d);
	reader.ignore();//removes all unread stuff from reader
	getline(reader, e);
	cout << "Sum: " << a + b << endl;
}
else
{
	cout << "Reading error" << endl;
}
reader.close();
return 0;
}*/
Settings::Settings()
{
	setFile("../../Data/Settings.txt");
	// Define default values incase load dosen't load all values
	setWindowWidth(640);
	setWindowHeight(480);
	setWindowMode(0);
	setMonitor(0);
	// Attempt to load the file
	//XXX:load();
}
void Settings::setFile(string path)
{
	this->filePath = path;
}
string Settings::getFile()
{
	return filePath;
}
void Settings::setWindowWidth(const int width)
{
	windowWidth = width;
}
int Settings::getWindowWidth()
{
	return windowWidth;
}
void Settings::setWindowHeight(const int height)
{
	windowHeight = height;
}
int Settings::getWindowHeight()
{
	return windowHeight;
}
void Settings::setWindowMode(const int mode)
{
	windowMode = mode;
}
int Settings::getWindowMode()
{
	return windowMode;
}
void Settings::setMonitor(const int monitor)
{
	this->monitor = monitor;
}
int Settings::getMonitor()
{
	return monitor;
}
// The aspect ratio for the current width/height
double Settings::getAspectRatio()
{
	if(windowHeight<1)
	{
		return 1.0;
	}
	else
	{
		return ((double)windowWidth)/((double)windowHeight);
	}
}
bool Settings::load(const string path)
{
	bool output = false;
	ifstream reader(path);
	if (reader.is_open())
	{
		reader >> windowWidth;
		reader >> windowHeight;
		reader >> windowMode;
		reader >> monitor;
		output = true;
	}
	reader.close();
	return output;
}
bool Settings::load()
{
	return load(filePath);
}
bool Settings::save(const string path)
{
	bool output = false;
	ofstream writer(path);
	if (writer.is_open())
	{
		writer << windowWidth << endl;
		writer << windowHeight << endl;
		writer << windowMode << endl;
		writer << monitor << endl;
		output = true;
	}
	writer.close();
	return output;
}
bool Settings::save()
{
	return save(filePath);
}
// Resize method
void Settings::resize(const int width, const int height)
{
	setWindowWidth(width);
	setWindowHeight(height);
}