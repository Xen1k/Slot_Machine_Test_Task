#include "button.h"

Button::Button(Dimensions textureDimensions, int textSizeX, int textSizeY, std::string texturePath, std::string label)
	: GameObject(textureDimensions, texturePath), textSizeX(textSizeX), textSizeY(textSizeY), label(label) {};


void Button::Render(bool flip)
{
	GameObject::Render(flip);
	engine.RenderText(label, textColor, fontSize, xPos, yPos, textSizeX, textSizeY);
}
