#include "Texture.h"
#include <iostream>

Texture::Texture(const char* fileName)
	: bitmap(al_load_bitmap(fileName))
{
	if (bitmap == NULL)
	{
		throw ContentLoadFailedException(fileName, "Texture not found. Texture::Texture() Ln 9.");
	}
}

Texture::~Texture()
{
	al_destroy_bitmap(bitmap);
}