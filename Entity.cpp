#include "Entity.h"
#include "Engine.h"
#include "Alert.h"

Entity::Entity() : Transform()
{
    Engine::AddEntity(this); // zastanów sie czy jest sens robic to z shared_ptr
	Engine::AddTransform(this); // a jezli tak to jak to zrobic
}
Entity::~Entity()
{
    delete sprite;
    delete colider;
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
    if (colider)
        delete colider;

    sprite = new sf::Sprite(texture);
    colider = new Colider(texture.getSize());

    if (!spriteAlreadyAdded)
    {
        Engine::AddSprite(sprite);
        spriteAlreadyAdded = true;
    }

    return true;
}

void Entity::SetScale(const sf::Vector2u& scale)
{
    Transform::SetScale(scale);
    sprite->setScale((sf::Vector2f)scale);
    colider->SetScale(scale);
}