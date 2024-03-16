#pragma once
#include <vector>
#include "barrelTile.h"

// ������� ��������
class Barrel
{
private:
	const int numOfTilesInBarrel;
	std::vector<BarrelTile*> tiles;
	std::vector<std::string> tileTextures = { "Sprites/bomb.png", "Sprites/eye.png", "Sprites/tIcon.png" };
	int yPos;
	int xPos;
	float rotationSpeed = 400;
	// �� ������� ������ ��� ��������� ������� ����� ������ ������� �������������
	int numOfRotatedTiles = 0;
	
public:
	// ���������� �������� ����� ����� ���������� ������������ ������
	int tilesToRotate = 10;
	void Reset();
	void Render();
	void Rotate(bool countRotatedTiles);
	inline int GetNumOfRotatedTiles() const { return numOfRotatedTiles; }
	inline void SetRotationSpeed(int speed) { rotationSpeed = speed; }
	Barrel(int xPos, int yPos, int numOfTilesInBarrel);
	~Barrel();
	static const int numOfShowedTiles = 3;
};