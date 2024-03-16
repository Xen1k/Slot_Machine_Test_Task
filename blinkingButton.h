#pragma once
#include "button.h"
#include "timer.h"

// Кнопка, которая меняет свой цвет между двумя указанными через определённый интервал времени
class BlinkingButton : public Button
{
private:
	SDL_Color textColorMain = { 255, 255, 0 };
	SDL_Color textColorBlink = { 255, 255, 0 };
	Timer startButtonBlinkTimer;
	bool showsBlinkColor = false;
public:
	int blinkingPeriodMs;
	BlinkingButton(Dimensions dimensions, int textSizeX, int textSizeY, std::string texturePath, std::string label, int blinkingPeriodMs);
	void BlinkOnTimer();
	inline void SetColors(SDL_Color color1, SDL_Color color2)
	{
		textColorMain = color1;
		textColorBlink = color2;
		textColor = textColorMain;
	}
};