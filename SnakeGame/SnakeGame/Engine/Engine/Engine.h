#pragma once

#include "Time.h"
#include "../Structures/IGame.h"

namespace Lamter
{
	class Engine
	{
	private:
		Time* gameTime;
		IGame& game;

	public:
		Engine(IGame& _game, int targetFPS);
		~Engine();
		void Run();
	};

}

