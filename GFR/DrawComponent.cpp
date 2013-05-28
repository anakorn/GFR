#include "DrawComponent.h"

using namespace framework;

void DrawComponent::Initialize(Texture* texture)
{
	SetTexture(texture);
	m_Animation = nullptr;
	m_Rotation = 0;
};

void DrawComponent::SetAnimation(Animation* animation)
{
	m_Animation = animation;
};

Animation* DrawComponent::GetAnimation()
{
	return m_Animation;
};

void DrawComponent::SetTexture(Texture* texture)
{
	m_Texture = texture;
};

const Texture& DrawComponent::GetTexture()
{
	return *m_Texture;
};

void DrawComponent::SetOrigin(const Vec2f& origin)
{
	m_Origin = origin;
};

Vec2f DrawComponent::GetOrigin()
{
	return m_Origin;
};

void DrawComponent::SetPosition(const Vec2f& position)
{
	m_Position = position;
};

Vec2f DrawComponent::GetPosition()
{
	return m_Position;
};

void DrawComponent::SetRotation(const f32& rotation)
{
	m_Rotation = rotation;
};

f32 DrawComponent::GetRotation()
{
	return m_Rotation;
};

void DrawComponent::SetX(f32& x)
{
	f32 y = m_Position.y();
	m_Position = Vec2f(x, y);
};

f32 DrawComponent::GetX()
{
	return m_Position.x();
};

void DrawComponent::SetY(f32& y)
{
	f32 x = m_Position.x();
	m_Position = Vec2f(x, y);
};

f32 DrawComponent::GetY()
{
	return m_Position.y();
};

void DrawComponent::SetVisible(bool visible)
{
	m_IsVisible = visible;
};

const bool DrawComponent::IsVisible()
{
	return m_IsVisible;
};