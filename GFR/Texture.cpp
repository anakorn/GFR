#include "Texture.h"
#include "GFR_AL.h"
#include "ContentLoadException.h"

using namespace framework;

Texture::Texture(ALLEGRO_BITMAP* bitmap)
	: m_Bitmap(bitmap)
{
};

Texture::~Texture()
{
	GFR_AL::DestroyBitmap(m_Bitmap);
};
