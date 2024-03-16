#include "gameObject.h"

GameObject::GameObject(Dimensions dimensions, std::string texturePath) :
	xPos(dimensions.xPos), yPos(dimensions.yPos), width(dimensions.width), height(dimensions.height), engine(Engine::Locate())
{
	texture = engine.LoadTexture(texturePath);
}

bool GameObject::CheckIfMouseIsInBounds()
{
	Coordinates mousePos = engine.GetInput().getMousePos();
	return mousePos.x > xPos - width / 2 && mousePos.x < xPos + width / 2 && mousePos.y > yPos - height / 2 && mousePos.y < yPos + height / 2;
}

void GameObject::Translate(float xOffset, float yOffset)
{
	xPos += xOffset;
	yPos += yOffset;
}

void GameObject::Render(bool flip)
{
	engine.RenderTexture(texture, xPos, yPos, width, height, flip);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}

