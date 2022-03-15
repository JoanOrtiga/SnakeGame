#pragma once

#include "Time.h"
#include "../Structures/IGame.h"
#include "../Classes/COORD.h"

namespace Lamter
{
	class Engine
	{
	private:
		Time* gameTime;
		IGame* game;
		bool exitGame = false;

	public:
		Engine(IGame* _game, int targetFPS, COORD consoleBufferSize, bool showCursor);
		~Engine();
		void Run();
	};

}

