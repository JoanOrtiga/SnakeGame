#pragma once

#include <Windows.h>

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
		Engine(IGame& _game, int targetFPS, COORD consoleBufferSize, bool showCursor);
		~Engine();
		void Run();
	};

}

