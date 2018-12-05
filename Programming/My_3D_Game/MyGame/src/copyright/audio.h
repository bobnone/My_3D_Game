#ifndef AUDIO_H
#define AUDIO_H

#include <ALmixer/ALmixer.h>
#include <iostream>
using namespace std;

#define ENABLE_ALMIXER_THREADS
#define MAX_SOURCES 16

class Audio
{
public:
	// channel number and string for file path
	Audio(int channel, const char* fileName);
	~Audio();
	// int times is number the number of times to loop/replay
	void play(int times);
protected:
private:
	ALmixer_Data* data;
	int channel;
};
#endif