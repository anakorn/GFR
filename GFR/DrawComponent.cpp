#include "DrawComponent.h"

using namespace framework;

void DrawComponent::SetTexture(Texture& texture)
{
	m_Texture = &texture;
};

const Texture& DrawComponent::GetTexture()
{
	return *m_Texture;
};

void DrawComponent::SetPosition(f32 x, f32 y)
{
	m_X = x;
	m_Y = y;
};

void DrawComponent::SetX(f32 x)
{
	m_X = x;
};

f32 DrawComponent::GetX()
{
	return m_X;
};

void DrawComponent::SetY(f32 y)
{
	m_Y = y;
};

f32 DrawComponent::GetY()
{
	return m_Y;
};

void DrawComponent::SetVisible(bool visible)
{
	m_IsVisible = visible;
};

const bool DrawComponent::IsVisible()
{
	return m_IsVisible;
};
