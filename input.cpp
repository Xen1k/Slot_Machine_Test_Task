#include "input.h"
#include <SDL.h>

Coordinates Input::getMousePos()
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	return { mx, my };
}