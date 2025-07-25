#pragma once
#include <vector>
#include "Colider.h"
#include "Entity.h"

class Physics
{
private:
	//////////////////////////////////////////////////////////////////////
	// WE NEED SMTH LIKE EVENT WHEN OBJECT COLIDING DO SMTH IN COLIDER.H//
	//////////////////////////////////////////////////////////////////////
	inline static std::vector<Colider*> colidersArray;
public:
	static void AddColider(Colider* colider);
	static Colider* GetCollisions(); // Check collisions in updateloop
	static bool CheckCollision(Entity* firstEntity, Entity* secEntity); // cehck collision of 2 object
};

