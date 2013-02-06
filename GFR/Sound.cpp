#include "Sound.h"

Sound::Sound(const char* soundFile)
	: sound(NULL)
{
	sound = al_load_sample(soundFile);
}

Sound::~Sound()
{
	al_destroy_sample(sound);
}

void Sound::play()
{
	al_play_sample(sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Sound::loop()
{
	al_play_sample(sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}