#include "Colider.h"

Colider::Colider(const sf::Vector2u& size, const sf::Vector2u& scale)
{
	this->size = new sf::Vector2u(size);
	this->scale = new sf::Vector2u(scale);
}
//////////
//PUBLIC//
//////////
void Colider::SetScale(const sf::Vector2u& scale)
{
	this->scale = new sf::Vector2u(scale);
}

void Colider::SetSize(const sf::Vector2u& size)
{
	this->size = new sf::Vector2u(size);
}

sf::Vector2u Colider::GetSize()
{
	return sf::Vector2u{ size->x * scale->x, size->y * scale->y };
}
