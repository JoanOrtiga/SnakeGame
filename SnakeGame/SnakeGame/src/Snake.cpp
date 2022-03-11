#include "Snake.h"

#include "../Engine/Input/InputManager.h"
#include "../Engine/Console/ConsoleController.h"


Snake::Snake()
{
	//player = new Player(5);
}

Snake::~Snake() = default;

bool Snake::ExitGame()
{
	return false;
}

int posX;
int posY;

void Snake::Update(double dt)
{
	if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::D))
	{
		posX = min(Lamter::ConsoleController::GetConsoleBufferSize().X, posX++);
	}
	else if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::A))
	{
		posX--;
	}
	else if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::S))
	{
		posY++;
	}
	else if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::W))
	{
		posY--;
	}
	//player->Update(dt);

	
}

void Snake::DrawnUpdate()
{
	//player->DrawnUpdate();
}

void Snake::Draw()
{
	Lamter::ConsoleController::DrawAt(char(219), posX, posY);
	//player->Draw();
}

