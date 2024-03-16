#pragma once
#include <SDL.h>
#include "utils.h"
#include "engine.h"

struct Dimensions
{
	int xPos;
	int yPos;
	int width;
	int height;
};

// Реализует игровой объект, имеющий текстуру, размер и координаты 
class GameObject
{
protected:
	SDL_Texture* texture;
	Engine& engine;
public:
	
	GameObject() = default;
	virtual ~GameObject();

	void Translate(float xOffset, float yOffset);

	int height;
	int width;
	float xPos;
	float yPos;

	GameObject(Dimensions dimensions, std::string texturePath);
	virtual void Render(bool flip = false);
	bool CheckIfMouseIsInBounds();

};