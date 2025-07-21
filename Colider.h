#pragma once
#include <SFML/Graphics.hpp>
class Colider
{
private:
	float width;
	float height;
public:
	// Do collision in physic
	Colider(const sf::Vector2f& size);
};

