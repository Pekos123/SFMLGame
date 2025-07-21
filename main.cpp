#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
    sf::RenderWindow* window = Engine::CreateWindow({ 200, 200 }, "SFML works!");

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