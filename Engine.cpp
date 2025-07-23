#include "Engine.h"

///////////
//PRIVATE//
///////////
void Engine::DrawSprites()
{
	for (sf::Sprite* sprite : spritesArray)
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

void Engine::SyncSpirtesPositionsWithTransform()
{
	for (Entity* entity : entitesArray)
	{
		entity->sprite->setPosition({ entity->position.x, -entity->position.y });
	}
}
//////////
//PUBLIC//
//////////
void AddSprite(sf::Sprite* sprite)
{
	spritesArray.push_back(sprite);
}
void AddTransform(Transform* transform)
{
	transformsArray.push_back(transform);
}
void AddEntity(Entity* entity)
{
	entitesArray.push_back(entity);
}

sf::RenderWindow* CreateWindow(const sf::Vector2u& size, const std::string& title, bool fullscreen = false)
{
	windowTitle = title;
	windowFullscreen = fullscreen;

	sf::State state = fullscreen ? sf::State::Fullscreen : sf::State::Windowed;
	window = sf::RenderWindow(sf::VideoMode(size), title, sf::Style::Default, state);

	return &window;
}
sf::RenderWindow* GetWindow()
{
	if (&window != nullptr)
		return &window;
	else
		Alert::ERROR("There is no window created, create window first");
}
void SetResolution(const sf::Vector2u& size)
{
	window.setSize(size);
}
void SetFullscreen(const bool& fullscreen = false, const sf::Vector2u& size = window.getSize())
{
	CreateWindow(window.getSize(), windowTitle, fullscreen);
}

void Update()
{
	deltaTime = (float)gameClock.restart().asMilliseconds();

	window.clear();
	SyncSpirtesPositionsWithTransform();
	DrawSprites();
	window.display();
}