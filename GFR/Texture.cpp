#include "Texture.h"
#include "GFRAL_ContentMgr.h"
#include "ContentLoadException.h"

using namespace framework;

Texture::Texture(ALLEGRO_BITMAP* bitmap)
	: m_Bitmap(bitmap)
{
};

Texture::~Texture()
{
	GFRAL_ContentMgr::DestroyBitmap(m_Bitmap);
};
