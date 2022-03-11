#include "Engine.h"

#include "Random.h"
#include "../Input/InputManager.h"
#include "../Console/ConsoleController.h"

namespace Lamter
{
	Engine::Engine(IGame& _game, int targetFPS, COORD consoleBufferSize, bool showCursor) : gameTime(new Time(targetFPS)), game(_game)
	{
		ConsoleController::Init(consoleBufferSize, showCursor);
		InputManager::Init();
		Random::Init();
	}

	void Engine::Run()
	{
		while (!game.ExitGame())
		{
			InputManager::UpdateInput();

			bool normalUpdate;
			const bool shouldDraw = gameTime->ShouldDrawNextFrame(normalUpdate);

			if(normalUpdate)
				game.Update(gameTime->deltaSeconds);

			if(shouldDraw)
			{
				game.DrawnUpdate();
				game.Draw();
			}
		}
	}

	Engine::~Engine()
	{
		delete &game;
		delete gameTime;
	}
}
