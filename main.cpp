#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Entity.h"
#include "Physics.h"
#include "Event.h"

void MovePlayer(Entity* entity);
void OnCollision();

int i = 0;

int main()
{
    sf::RenderWindow* window = Engine::CreateWindow({ 1280, 720 }, "Game!");

    Entity entity;
    entity.SetTexture("images/sprite2.jpg");
    entity.position = { 20, 20 };

    Entity test;
    test.SetTexture("images/sprite2.jpg");
    test.position = { 500, -50 };
    test.SetScale({ 2, 2 });

    Event coliding;
    coliding.AddListener(OnCollision);

    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }
        
        if (Physics::CheckCollision(&entity, &test))
            coliding.Invoke();
        
        MovePlayer(&entity);

        Engine::Update();
    }
}

void MovePlayer(Entity* entity)
{
    float speed = 1;

    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        direction = { speed * Engine::deltaTime, 0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        direction = { -speed * Engine::deltaTime, 0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        direction = { 0, speed * Engine::deltaTime };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        direction = { 0, -speed * Engine::deltaTime };
    entity->position += direction;
}

void OnCollision()
{
    std::cout << "coliision " << i << std::endl;
    i++;
}