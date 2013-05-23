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
	m_x = x;
	m_y = y;
};

void DrawComponent::SetX(f32 x)
{
	m_x = x;
};

f32 DrawComponent::GetX()
{
	return m_x;
};

void DrawComponent::SetY(f32 y)
{
	m_y = y;
};

f32 DrawComponent::GetY()
{
	return m_y;
};
