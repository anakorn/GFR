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