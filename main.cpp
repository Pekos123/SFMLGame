#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Entity.h"

int main()
{
    sf::RenderWindow* window = Engine::CreateWindow({ 400, 400 }, "Game!");
    Entity entity;
    entity.SetTexture("images/sprite2.jpg");
    entity.position = { 20, 20 };
    float speed = 1;

    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
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