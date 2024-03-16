#include "barrel.h"
#include "sdlTime.h"

Barrel::Barrel(int xPos, int yPos, int numOfTilesInBarrel) : numOfTilesInBarrel(numOfTilesInBarrel), yPos(yPos), xPos(xPos)
{
	for (int i = 0; i < numOfTilesInBarrel; ++i)
		tiles.push_back(new BarrelTile(xPos, i * BarrelTile::tileSize - BarrelTile::tileSize / 2 + yPos, tileTextures[rand() % tileTextures.size()]));
}

void Barrel::Render()
{
	for (auto tile : tiles)
		tile->Render();
}

void Barrel::Reset()
{
	numOfRotatedTiles = 0;
}


void Barrel::Rotate(bool countRotatedTiles)
{
	for (auto tile : tiles)
	{
		tile->Translate(0, rotationSpeed * Time::GetDeltaTime());
		if (tile->yPos >= numOfTilesInBarrel * BarrelTile::tileSize + yPos - BarrelTile::tileSize / 2)
		{
			tile->yPos = -BarrelTile::tileSize / 2 + yPos;
			if (countRotatedTiles)
				numOfRotatedTiles++;
		}
	}
}

Barrel::~Barrel()
{
	for (auto tile : tiles)
		delete tile;
}