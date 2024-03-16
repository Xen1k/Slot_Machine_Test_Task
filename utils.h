#ifndef utils
#define utils

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>




void RenderText(const std::string &message, TTF_Font *font,
	SDL_Color color, int fontSize, SDL_Renderer *renderer, float scaleW, float scaleH, int x, int y);
#endif // !utils

