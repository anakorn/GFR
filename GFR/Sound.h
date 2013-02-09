// Sound.h
// Wrapper for allegro (in progress)

#ifndef GFR_FRAMEWORK_TYPES_SOUND_H
#define GFR_FRAMEWORK_TYPES_SOUND_H

#include <string>
#include <allegro5/allegro_audio.h>

class Sound
{
public:
	Sound(const char* soundFile);
	~Sound();

	ALLEGRO_SAMPLE* getSound()
	{
		return sound;
	}

private:
	ALLEGRO_SAMPLE* sound;

};

#endif