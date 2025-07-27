#include "Physics.h"
#include "SFML/Graphics.hpp"

///////////
//PRIVATE//
///////////


//////////
//PUBLIC//
//////////
void Physics::AddColider(std::shared_ptr<Colider> colider)
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

	sf::Vector2u firstColSize = firstEntity->colider->GetSize();
	sf::Vector2u secColSize = secEntity->colider->GetSize();

	bool colidingX = (firstPos.x + firstColSize.x > secPos.x) && (firstPos.x < secPos.x + secColSize.x);
	bool colidingY = (firstPos.y + firstColSize.y > secPos.y) && (firstPos.y < secPos.y + secColSize.y);

	//delete firstCol;
	//delete secCol;

	if(colidingX && colidingY)
		return true;
	return false;
}

