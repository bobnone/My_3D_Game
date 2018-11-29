/*void Audio::list_audio_devices(const ALCchar *devices)
{
	const ALCchar *device = devices, *next = devices + 1;
	size_t len = 0;

	fprintf(stdout, "Devices list:\n");
	fprintf(stdout, "----------\n");
	while (device && *device != '\0' && next && *next != '\0')
	{
		fprintf(stdout, "%s\n", device);
		len = strlen(device);
		device += (len + 1);
		next += (len + 2);
	}
	fprintf(stdout, "----------\n");
}
bool Audio::errorCheck(const char* message)
{
	ALenum error = alGetError();
	if (error != AL_NO_ERROR)
	{
		fprintf(stderr, message, "\n");
		return true;
	}
	return false;
}
ALenum Audio::to_al_format(short channels, short samples)
{
	bool stereo = (channels > 1);

	switch (samples)
	{
	case 16:
		if (stereo)
		{
			return AL_FORMAT_STEREO16;
		}
		else
		{
			return AL_FORMAT_MONO16;
		}
	case 8:
		if (stereo)
		{
			return AL_FORMAT_STEREO8;
		}
		else
		{
			return AL_FORMAT_MONO8;
		}
	default:
		return -1;
	}
}
Audio::Audio(const char* fileName)
{
	ALboolean enumeration;
	const ALCchar* devices;
	const ALCchar* defaultDeviceName;
	ALCdevice* device;
	ALCcontext* context;
	ALuint buffer, source;
	ALfloat listenerOri[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
	ALint source_state;
	ALmixer_Data* data;

	enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
	if (enumeration == AL_FALSE)
	{
		fprintf(stderr, "enumeration extension not available\n");
	}
	else
	{
		list_audio_devices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));
	}
	defaultDeviceName = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
	device = alcOpenDevice(defaultDeviceName);
	if (!device)
	{
		fprintf(stderr, "unable to open default device\n");
	}

	fprintf(stdout, "Device: %s\n", alcGetString(device, ALC_DEVICE_SPECIFIER));

	alGetError();

	context = alcCreateContext(device, NULL);
	if (!alcMakeContextCurrent(context))
	{
		fprintf(stderr, "failed to make default context\n");
	}
	errorCheck("make default context");

	// set orientation
	alListener3f(AL_POSITION, 0, 0, 1.0f);
	errorCheck("listener position");
	alListener3f(AL_VELOCITY, 0, 0, 0);
	errorCheck("listener velocity");
	alListenerfv(AL_ORIENTATION, listenerOri);
	errorCheck("listener orientation");

	alGenSources((ALuint)1, &source);
	errorCheck("source generation");
	alSourcef(source, AL_PITCH, 1);
	errorCheck("source pitch");
	alSourcef(source, AL_GAIN, 1);
	errorCheck("source gain");
	alSource3f(source, AL_POSITION, 0, 0, 0);
	errorCheck("source position");
	alSource3f(source, AL_VELOCITY, 0, 0, 0);
	errorCheck("source velocity");
	alSourcei(source, AL_LOOPING, AL_FALSE);
	errorCheck("source looping");

	alGenBuffers(1, &buffer);
	errorCheck("buffer generation");

	//load data

	alSourcei(source, AL_BUFFER, buffer);
	errorCheck("buffer binding");

	ALboolean init = ALmixer_Init(ALMIXER_DEFAULT_FREQUENCY, ALMIXER_DEFAULT_NUM_SOURCES, ALMIXER_DEFAULT_REFRESH);
	data = ALmixer_LoadAll(fileName, 0);
	ALint loops = 2;
	ALuint 	ALmixer_PlaySource(source);// , data, loops);
	//alSourcePlay(source);
	errorCheck("source playing");

	alGetSourcei(source, AL_SOURCE_STATE, &source_state);
	errorCheck("source state get");
	while (source_state == AL_PLAYING)
	{
		alGetSourcei(source, AL_SOURCE_STATE, &source_state);
		errorCheck("source state get");
	}

	// exit context
	ALmixer_FreeData(data);
	ALmixer_Quit();

	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);
	device = alcGetContextsDevice(context);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}*/

#include "audio.h"

ALboolean g_PlayingAudio[MAX_SOURCES];

void Internal_SoundFinished_CallbackIntercept(ALint which_channel, ALuint al_source, ALmixer_Data* almixer_data, ALboolean finished_naturally, void* user_data)
{
	fprintf(stderr, "Channel %d finished\n", which_channel);
	g_PlayingAudio[which_channel] = AL_FALSE;
}
// channel number and string for file path
Audio::Audio(int channel, const char* fileName)
{
	this->channel = channel;
	ALmixer_Init(22050, 0, 0);
	if (!(data = ALmixer_LoadAll(fileName, AL_FALSE)))
	{
		printf("%s. Quiting program.\n", ALmixer_GetError());
		exit(1);
	}
	ALmixer_SetPlaybackFinishedCallback(Internal_SoundFinished_CallbackIntercept, NULL);
	printf("Is wav available: %d\n", ALmixer_IsDecoderAvailable("wav"));
	printf("Is ogg available: %d\n", ALmixer_IsDecoderAvailable("ogg"));
	printf("Is mp3 available: %d\n", ALmixer_IsDecoderAvailable("mp3"));
	printf("Is mp4 available: %d\n", ALmixer_IsDecoderAvailable("mp4"));
	play(0);
}
// int times is number the number of times to loop/replay
void Audio::play(int times)
{
	g_PlayingAudio[channel] = AL_TRUE;
	ALmixer_PlayChannel(channel, data, times);
}
Audio::~Audio()
{
	ALmixer_FreeData(data);
	ALmixer_Quit();
}