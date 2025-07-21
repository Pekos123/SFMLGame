#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
    sf::RenderWindow* window = Engine::CreateWindow({ 400, 400 }, "Game!");

    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }
        Engine::Update();
    }
}