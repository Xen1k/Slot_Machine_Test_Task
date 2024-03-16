#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "input.h"

// Класс, упрощающий взаимодействие с SDL
class Engine
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* mainFont;
	SDL_Window* CreateWindow();
	SDL_Renderer* CreateRenderer(SDL_Window* window);
	Input input;
	Engine();

public:
	static Engine& Locate();

	inline Input& GetInput() { return input; };
	inline SDL_Renderer* GetRenderer() { return renderer; }
	SDL_Texture* LoadTexture(const std::string& file);
	void RenderTexture(SDL_Texture* tex, int xPos, int yPos, int width, int height, bool flip);
	void RenderText(const std::string message, SDL_Color textColor, int fontSize, int xPos, int yPos, float width, float height);

	

	Engine(Engine const&) = delete;
	void operator=(Engine const&) = delete;

	static const int SCREEN_WIDTH = 500;
	static const int SCREEN_HEIGHT = 500;
};