#ifndef GFR_FRAMEWORK_TYPES_SOUND_H
#define GFR_FRAMEWORK_TYPES_SOUND_H

#include <allegro5/allegro_audio.h>

namespace framework
{
	/*	ALLEGRO_SAMPLE type abstraction.
	*/
	class Sound
	{
	public:
		Sound				(ALLEGRO_SAMPLE* sample);
		~Sound				();

		ALLEGRO_SAMPLE*		GetSample() const { return m_Sample; }

	private:
		ALLEGRO_SAMPLE*		m_Sample;

	};
};

#endif