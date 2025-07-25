#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Transform.h"
#include "Colider.h"

class Entity : public Transform
{
private:
    bool spriteAlreadyAdded = false;

public:
    Entity();
    ~Entity();
    sf::Texture texture;
    sf::Sprite* sprite = nullptr;
    Colider* colider = nullptr;

    bool SetTexture(const std::string& path);
};