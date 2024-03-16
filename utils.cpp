#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "utils.h"
#include <SDL_ttf.h>

void RenderText(const std::string &message, TTF_Font *font,
	SDL_Color color, int fontSize, SDL_Renderer *renderer, float scaleW, float scaleH, int x, int y)
{
	SDL_Surface *surf = TTF_RenderUTF8_Blended(font, message.c_str(), color);
	if (surf == nullptr) {
		TTF_CloseFont(font);
		std::cout << "Error: can't load font!" << std::endl;
		return;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = scaleW;
	dst.h = scaleH;

	SDL_RenderCopy(renderer, texture, NULL, &dst);

	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}

