#include "Entity.h"
#include "Engine.h"
#include "Alert.h"

Entity::Entity() : Transform()
{
	Engine::AddEntity(this);
	Engine::AddTransform(this);
}
Entity::~Entity()
{
	delete sprite;
	sprite = nullptr; // To prevent dangling pointer
}

bool Entity::SetTexture(const std::string& path)
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