#include "Transform.h"

void Transform::SetScale(const sf::Vector2u& scale)
{
	this->scale = scale;
}

sf::Vector2u* Transform::GetScale()
{
	return &scale;
}