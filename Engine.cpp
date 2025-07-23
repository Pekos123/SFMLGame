#include "Engine.h"
#include "Alert.h"

float Engine::deltaTime = 0.0f;

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
			Alert::WARNING("Sprite have size of 0 -> propably no texture!");
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
void Engine::AddSprite(sf::Sprite* sprite)
{
	spritesArray.push_back(sprite);
}
void Engine::AddTransform(Transform* transform)
{
	transformsArray.push_back(transform);
}
void Engine::AddEntity(Entity* entity)
{
	entitesArray.push_back(entity);
}

sf::RenderWindow* Engine::CreateWindow(const sf::Vector2u& size, const std::string& title, bool fullscreen)
{
	windowTitle = title;
	windowFullscreen = fullscreen;

	sf::State state = fullscreen ? sf::State::Fullscreen : sf::State::Windowed;
	window = sf::RenderWindow(sf::VideoMode(size), title, sf::Style::Default, state);

	return &window;
}
sf::RenderWindow* Engine::GetWindow()
{
	if (&window != nullptr)
		return &window;
	else
		Alert::ERROR("There is no window created, create window first");
}
void Engine::SetResolution(const sf::Vector2u& size)
{
	window.setSize(size);
}
void Engine::SetFullscreen(const bool& fullscreen, const sf::Vector2u& size)
{
	CreateWindow(window.getSize(), windowTitle, fullscreen);
}

void Engine::Update()
{
	deltaTime = (float)gameClock.restart().asMilliseconds();

	window.clear();
	SyncSpirtesPositionsWithTransform();
	DrawSprites();
	window.display();
}