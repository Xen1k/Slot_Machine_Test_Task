#include "barrelTile.h"

BarrelTile::BarrelTile(int xPos, int yPos, std::string texturePath) : 
	GameObject({ xPos, yPos, tileSize, tileSize }, texturePath) {};
