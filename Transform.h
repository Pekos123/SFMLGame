#pragma once
#include <SFML/System/Vector2.hpp>

class Transform
{
private:
    sf::Vector2u scale = { 1, 1 };
public:
    Transform() = default;
    virtual ~Transform() = default;

    sf::Vector2f position;

    virtual void SetScale(const sf::Vector2u& scale);
    sf::Vector2u* GetScale();
};