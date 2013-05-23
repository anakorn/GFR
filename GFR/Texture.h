#ifndef GFR_FRAMEWORK_TYPES_TEXTURE_H
#define GFR_FRAMEWORK_TYPES_TEXTURE_H

#include <allegro5/allegro.h>

namespace framework
{
	/*	ALLEGRO_BITMAP type abstraction.
	*/
	class Texture
	{
	public:
		Texture				(ALLEGRO_BITMAP* bitmap);
		~Texture			();

		ALLEGRO_BITMAP*		GetBitmap() const { return m_Bitmap; }

	protected:
		ALLEGRO_BITMAP*		m_Bitmap;

	};
};

#endif