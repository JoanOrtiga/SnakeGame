#include "Engine.h"

#include "Random.h"
#include "../Input/InputManager.h"

namespace Lamter
{
	Engine::Engine(Game& _game, int targetFPS) : gameTime(new Time(targetFPS)), game(_game)
	{
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
