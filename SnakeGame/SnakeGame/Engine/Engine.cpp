#include "Engine.h"

namespace Lamter
{
	Engine::Engine()
	{
		InputManager::Init();
	}

	void Engine::Update()
	{
		InputManager::UpdateInput();
	}
}
