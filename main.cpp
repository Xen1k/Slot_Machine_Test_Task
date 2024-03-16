#pragma execution_character_set("utf-8")

#include <iostream>
#include <ctime>
#include "utils.h"
#include "sdlTime.h"
#include <string>
#include "blinkingButton.h"
#include "engine.h"
#include "barrel.h"
#include "fpsCounter.h"
#include "gameSettings.h"

SDL_Event e;

const int numOfBarrels = 5;

BlinkingButton* startButton;
GameObject* barrelsOverlay;
// Барабаны, представляющие автомат
std::vector<Barrel*> barrels;
// Для последовательной оставноки барабанов. Показывает, барабан с каким индексом должен быть остановлен следующим
int nextBarrelToStop = 0;

FpsCounter fpsCounter;
SDL_Color fpsTextColor = { 255, 255, 255 };

void OnStartClicked()
{
	for (auto barrel : barrels)
	{
		barrel->tilesToRotate = Settings::minBarrelTilesToRotate + rand() % Settings::maxBarrelTilesToRotate;
		barrel->SetRotationSpeed(Settings::minBarrelRotationSpeed + rand() % Settings::maxBarrelRotationSpeed);
		barrel->Reset();
	}
	nextBarrelToStop = 0;
}

// Выполняется каждый кадр
bool Update()
{
	Time::SetNow(SDL_GetPerformanceCounter());
	SDL_RenderClear(Engine::Locate().GetRenderer());

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return false;
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (startButton->CheckIfMouseIsInBounds())
				OnStartClicked();
		}
	}

	// Вращение и рендер барабанов
	for (int i = 0; i < barrels.size(); ++i)
	{
		if (barrels[i]->GetNumOfRotatedTiles() < barrels[i]->tilesToRotate || nextBarrelToStop < i)
			barrels[i]->Rotate(nextBarrelToStop == i);
		else if (i >= nextBarrelToStop)
			nextBarrelToStop++;
		barrels[i]->Render();
	}


	barrelsOverlay->Render();
	startButton->BlinkOnTimer();
	startButton->Render();

	// Отображение fps
	std::string fpsText = "FPS: " + std::to_string(fpsCounter.GetLastFps());
	Engine::Locate().RenderText(fpsText, fpsTextColor, 300, 100, Engine::SCREEN_HEIGHT - 50, fpsText.length() * 10, 35);



	SDL_RenderPresent(Engine::Locate().GetRenderer());
	fpsCounter.ProceedCount();
	Time::Calculate();
	return true;
}

int main(int argc, char** argv)
{
	srand(time(0));

	barrels.reserve(numOfBarrels);
	for (int i = 0; i < numOfBarrels; ++i)
	{
		barrels.push_back(new Barrel(Engine::SCREEN_WIDTH / 2 + (numOfBarrels / 2 - i) * BarrelTile::tileSize * (-1), 0, 8));
		barrels[i]->tilesToRotate = 0;
	}
	barrelsOverlay = new GameObject({
		Engine::SCREEN_WIDTH / 2,
		Engine::SCREEN_HEIGHT / 2 + BarrelTile::tileSize * Barrel::numOfShowedTiles / 2,
		Engine::SCREEN_WIDTH,
		Engine::SCREEN_HEIGHT - BarrelTile::tileSize * Barrel::numOfShowedTiles }, "Sprites/black.png");
	startButton = new BlinkingButton({ Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT - 60, 100, 100 }, 80, 40, "Sprites/button.png", "Start", 300);
	startButton->SetColors({ 255, 255, 255 }, {200, 0, 90});
	while (Update());
	delete startButton;
	delete barrelsOverlay;
	for (auto barrel : barrels)
		delete barrel;

	return 0;
}

