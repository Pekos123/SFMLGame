#pragma once
#include <SFML/Graphics.hpp>
class Colider
{
public:
	sf::Vector2u* size = nullptr;
	// Do collision in physic
	Colider(const sf::Vector2u& size);
};

