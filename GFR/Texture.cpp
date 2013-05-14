#include "Texture.h"
#include "GFRAL_Content.h"
#include "ContentLoadException.h"

using namespace framework;

Texture::Texture(ALLEGRO_BITMAP* bitmap)
	: m_Bitmap(bitmap)
{
};

Texture::~Texture()
{
	GFRAL_Content::DestroyBitmap(m_Bitmap);
};
