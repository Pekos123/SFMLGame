#pragma once
#include "Engine.h"
#include "Alert.h"
#include "Transform.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public Transform
{
private:
    bool spriteAlreadyAdded = false;

public:
    Entity();
    ~Entity();
    sf::Texture texture;
    sf::Sprite* sprite = nullptr;

    bool SetTexture(const std::string& path)
    {
        if (!texture.loadFromFile(path))
        {
            Alert::WARNING("Nie uda³o siê za³adowaæ tekstury: " + path);
            return false;
        }
        if (sprite)
            delete sprite;

        sprite = new sf::Sprite(texture);

        if (!spriteAlreadyAdded)
        {
            Engine::AddSprite(sprite);
            spriteAlreadyAdded = true;
        }

        return true;
    }
};