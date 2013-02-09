// Texture.h
// Wrapper for allegro bitmaps

#ifndef GFR_FRAMEWORK_TYPES_TEXTURE_H
#define GFR_FRAMEWORK_TYPES_TEXTURE_H

#include <allegro5/allegro.h>

class Texture
{
public:
	Texture(const char* fileName);
	~Texture();

	ALLEGRO_BITMAP* getBitmap()
	{
		return bitmap;
	}

private:
	ALLEGRO_BITMAP* bitmap;

};

#endif