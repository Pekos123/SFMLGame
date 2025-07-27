#pragma once
#include <SFML/Graphics.hpp>
class Colider
{
private:
	sf::Vector2u* size = nullptr;
	sf::Vector2u* scale = nullptr;
public:
	
	// Do collision in physic
	Colider(const sf::Vector2u& size, const sf::Vector2u& scale = {1, 1});

	void SetScale(const sf::Vector2u& scale);
	void SetSize(const sf::Vector2u& size);
	sf::Vector2u GetSize();
};

