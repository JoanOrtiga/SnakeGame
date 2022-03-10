#pragma once

#include "Time.h"
#include "../Structures/Game.h"

namespace Lamter
{
	class Engine
	{
	private:
		Time* gameTime;
		Game& game;

	public:
		Engine(Game& _game, int targetFPS);
		~Engine();
		void Run();
	};

}

