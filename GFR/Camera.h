#ifndef GFR_FRAMEWORK_MANAGERS_CAMERA_CAMERA_H
#define GFR_FRAMEWORK_MANAGERS_CAMERA_CAMERA_H

#include "Common.h"
#include "allegro5\allegro.h"

namespace framework
{
	/*	Wrapper/manager class for Allegro view transformations.
	*/
	class Camera
	{
	public:
		Camera();

		void	Update		(void);

		void	Translate	(f32 amt_px_x, f32 amt_px_y, f32 amt_px_z = 0);
		void	Scale		(f32 amt_perc_x, f32 amt_perc_y);
		void	Rotate		(f32 amt_rad);

		void	ResetZoom	(void);
		void	ResetRotate	(void);

	private:
		ALLEGRO_TRANSFORM	m_View;

		f32		m_ScreenWidth;
		f32		m_ScreenHeight;

		//		View transform need only be updated on view change
		bool	m_IsViewChanged;

	};
};

#endif