#pragma once
#include "gameObject.h"

//  нопка - указанный текст и фонова€ текстура 
class Button : public GameObject
{
protected:
	std::string label;
	static const int fontSize = 20;
	int textSizeX;
	int textSizeY;
public:
	SDL_Color textColor = { 255, 255, 255, 0 };
	Button(Dimensions dimensions, int textSizeX, int textSizeY, std::string texturePath, std::string label);
	~Button() = default;
	void Render(bool flip = false) override;
};