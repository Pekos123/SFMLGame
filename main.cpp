#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Entity.h"
#include "Physics.h"

int main()
{
    sf::RenderWindow* window = Engine::CreateWindow({ 1280, 720 }, "Game!");
    Entity entity;
    entity.SetTexture("images/sprite2.jpg");
    entity.position = { 20, 20 };

    Entity test;
    test.SetTexture("images/sprite2.jpg");
    test.position = { 500, -50 };

    float speed = 1;

    int i = 0;
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }
        
        if (Physics::CheckCollision(&entity, &test))
        {
            i++;
            std::cout << i << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            entity.position += {speed * Engine::deltaTime, 0};
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            entity.position += {-speed * Engine::deltaTime, 0};
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            entity.position += {0, speed* Engine::deltaTime};
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            entity.position += {0, -speed * Engine::deltaTime};
        }
        Engine::Update();
    }
}