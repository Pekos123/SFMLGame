#pragma once
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Transform.h"

class Engine
{
private:
	inline static sf::RenderWindow window;
	inline static std::string windowTitle;
	inline static bool windowFullscreen = false;

	inline static std::vector<sf::Sprite*> spritesArray;
	inline static std::vector<Transform*> transformsArray;
	inline static std::vector<Entity*> entitesArray;

	inline static sf::Clock gameClock;

	static void DrawSprites();
	static void DrawColiders(bool draw = false);
	static void SyncSpirtesPositionsWithTransform();
public:
	static float deltaTime;

	static void AddSprite(sf::Sprite* sprite);
	static void AddTransform(Transform* transform);
	static void AddEntity(Entity* entity);

	static sf::RenderWindow* CreateWindow(const sf::Vector2u& size, const std::string& title, bool fullscreen = false);
	static sf::RenderWindow* GetWindow();
	static void SetResolution(const sf::Vector2u& size);
	static void SetFullscreen(const bool& fullscreen = false, const sf::Vector2u& size = window.getSize());

	static void Update();
};

