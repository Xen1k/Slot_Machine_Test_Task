#pragma once
#include "gameObject.h"

// ������ �������� ��������
class BarrelTile : public GameObject
{
public:
	static const int tileSize = 80;
	BarrelTile(int xPos, int yPos, std::string texturePath);
};