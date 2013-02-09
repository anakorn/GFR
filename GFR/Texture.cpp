#include "Texture.h"
#include "ContentLoadException.h"
#include <iostream>

Texture::Texture(const char* fileName)
	: bitmap(al_load_bitmap(fileName))
{
	if (bitmap == NULL)
	{
		throw ContentLoadException(fileName);
	}
}

Texture::~Texture()
{
	al_destroy_bitmap(bitmap);
}

ALLEGRO_BITMAP* getBitmap()
{
	return NULL;	
}