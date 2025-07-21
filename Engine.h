#pragma once
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Alert.h"

class Engine
{
private:
	inline static sf::RenderWindow window;
	inline static std::string windowTitle;
	inline static bool windowFullscreen = false;

	inline static std::vector<sf::Sprite*> spritesToDraw;
	inline static void Draw()
	{
		std::vector<sf::Sprite*> sprites = Engine::getSpritesToDraw();
		for (sf::Sprite* sprite : sprites)
		{
			sf::FloatRect bounds = sprite->getLocalBounds();
			if (bounds.size == sf::Vector2f(0, 0))
			{
				Alert::WARNING("Sprite ma zerowy rozmiar -> prawdopodobnie brak tekstury!");
				continue;
			}
			window.draw(*sprite);
		}
	}
public:
	static std::vector<sf::Sprite*> getSpritesToDraw()
	{
		return spritesToDraw;
	}
	static void AddSprite(sf::Sprite* sprite)
	{
		spritesToDraw.push_back(sprite);
	}

	static sf::RenderWindow* CreateWindow(const sf::Vector2u& size, const std::string& title, bool fullscreen = false)
	{
		windowTitle = title;
		windowFullscreen = fullscreen;

		sf::State state = fullscreen ? sf::State::Fullscreen : sf::State::Windowed;
		window = sf::RenderWindow(sf::VideoMode(size), title, sf::Style::Default, state);
		
		return &window;
	}
	static sf::RenderWindow* GetWindow()
	{
		if (&window != nullptr)
			return &window;
		else
			Alert::ERROR("There is no window created, create window first");
	}
	static void SetResolution(const sf::Vector2u& size)
	{
		window.setSize(size);
	}
	static void SetFullscreen(const bool& fullscreen = false, const sf::Vector2u& size = window.getSize())
	{
		CreateWindow(window.getSize(), windowTitle, fullscreen);
	}
	
	static void Update()
	{
		window.clear();
		Draw();
		window.display();
	}
};

