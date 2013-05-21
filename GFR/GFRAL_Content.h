#ifndef GFR_FRAMEWORK_ALLEGRO_SUBDIVISIONS_GFRAL_CONTENT_H
#define GFR_FRAMEWORK_ALLEGRO_SUBDIVISIONS_GFRAL_CONTENT_H

#include "allegro5/allegro.h"
#include <string>

namespace framework
{
	class GFRAL_Content
	{
	public:
		static void					SetDefaultDirectory		();
		static const std::string	GetContentDirectory		(const char* subFolder);
		static ALLEGRO_BITMAP*		CreateBitmap			(const char* pathFile);
		static void					DestroyBitmap			(ALLEGRO_BITMAP* bitmap);
		static ALLEGRO_SAMPLE*		CreateSample			(const char* pathFile);
		static void					DestroySample			(ALLEGRO_SAMPLE* sample);		
	};
};


#endif