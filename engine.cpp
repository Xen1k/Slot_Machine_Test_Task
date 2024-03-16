#include "engine.h"
#include <iostream>

Engine::Engine()
{
	TTF_Init();
	window = CreateWindow();
	renderer = CreateRenderer(window);
	std::cout << "ENGINE";
	mainFont = TTF_OpenFont("./progressPixel.ttf", 40);
}

Engine& Engine::Locate()
{
	static Engine instance;
	return instance;
}

void Engine::RenderTexture(SDL_Texture* tex, int xPos, int yPos, int width, int height, bool flip)
{
	SDL_Rect dst;
	dst.x = xPos - width / 2;
	dst.y = yPos - height / 2;
	dst.w = width;
	dst.h = height;
	SDL_RenderCopyEx(renderer, tex, nullptr, &dst, 0, NULL, flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

}


SDL_Texture* Engine::LoadTexture(const std::string& file)
{
	if (!renderer)
	{
		std::cout << "Failed to load a texture! No renderer created!" << std::endl;
		return nullptr;
	}

	SDL_Texture* texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture)
		std::cout << IMG_GetError() << std::endl;

	return texture;
}

void Engine::RenderText(const std::string message, SDL_Color textColor, int fontSize, int xPos, int yPos, float width, float height)
{
	SDL_Surface* surf = TTF_RenderUTF8_Blended(mainFont, message.c_str(), textColor);
	if (surf == nullptr) {
		TTF_CloseFont(mainFont);
		std::cout << "Error: can't load font!" << std::endl;
		return;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_Rect dst;
	dst.x = xPos - width / 2;
	dst.y = yPos - height/ 2;
	dst.w = width;
	dst.h = height;

	SDL_RenderCopy(renderer, texture, NULL, &dst);

	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}

SDL_Window* Engine::CreateWindow()
{
	SDL_Window* window = SDL_CreateWindow("Test task SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return NULL;
	}

	return window;
}

SDL_Renderer* Engine::CreateRenderer(SDL_Window* window)
{
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if (renderer == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return NULL;
	}

	return renderer;
}