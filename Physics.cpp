#include "Physics.h"
#include "SFML/Graphics.hpp"

///////////
//PRIVATE//
///////////


//////////
//PUBLIC//
//////////
void Physics::AddColider(Colider* colider)
{
	colidersArray.push_back(colider);
}
Colider* Physics::GetCollisions()
{
	return nullptr;
}
bool Physics::CheckCollision(Entity* firstEntity, Entity* secEntity)
{
	sf::Vector2f firstPos = firstEntity->sprite->getPosition();
	sf::Vector2f secPos = secEntity->sprite->getPosition();

	Colider* firstCol = firstEntity->colider;
	Colider* secCol = secEntity->colider;

	bool colidingX = (firstPos.x + firstCol->size->x > secPos.x) && (firstPos.x < secPos.x + firstCol->size->x);
	bool colidingY = (firstPos.y + firstCol->size->y > secPos.y) && (firstPos.y < secPos.y + firstCol->size->y);

	if(colidingX && colidingY)
		return true;
	return false;
}

