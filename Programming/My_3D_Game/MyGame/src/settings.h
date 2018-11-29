#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>
#include <iostream>
using namespace std;

class Settings
{
public:
	Settings();
	bool load();
	bool save();
	void resize(const int width, const int height);
	void setFile(const string path);
	string getFile();
	void setWindowWidth(const int width);
	int getWindowWidth();
	void setWindowHeight(const int height);
	int getWindowHeight();
	void setWindowMode(const int mode);
	int getWindowMode();
	void setMonitor(const int monitor);
	int getMonitor();
	double getAspectRatio(); // The aspect ratio for the current width/height
protected:
private:
	string filePath;
	int windowWidth;
	int windowHeight;
	int windowMode; // 0 = fullscreen, 1 = windowed, 2 = borderless
	int monitor; // 0 = primary
	int roomRender; // number of rooms to render around your current position

	bool load(const string path);
	bool save(const string path);
};
#endif