#include "Camera.h"

using namespace framework;

Camera::Camera()
{
	al_identity_transform(&m_View);
	m_IsViewChanged = true;
};

void Camera::Update(void)
{
	if (m_IsViewChanged) 
	{
		al_use_transform(&m_View);
		m_IsViewChanged = false;
	}
};

void Camera::Translate(f32 amt_px_x, f32 amt_px_y, f32 amt_px_z)
{
	al_translate_transform(&m_View, amt_px_x, amt_px_y);
	/*if (amt_px_z != 0.0f)
	{
		al_scale
	};*/
	m_IsViewChanged = true;
};

void Camera::Scale(f32 amt_perc_x, f32 amt_perc_y)
{
	al_scale_transform(&m_View, amt_perc_x, amt_perc_y);
	m_IsViewChanged = true;
};

void Camera::Rotate(f32 amt_rad)
{
	al_rotate_transform(&m_View, amt_rad);
	m_IsViewChanged = true;
};

void Camera::ResetZoom(void)
{
	
	m_IsViewChanged = true;
};

void Camera::ResetRotate(void)
{

	m_IsViewChanged = true;
};

