#include "Snake.h"

#include "../Engine/Input/InputManager.h"
#include "../Engine/Console/ConsoleController.h"


Snake::Snake() = default;

Snake::~Snake() = default;

void Snake::Init()
{
	player = new Player(5);
}

bool Snake::ExitGame()
{
	return false;
}

void Snake::Update(double dt)
{
	player->Update(dt);
}

void Snake::DrawnUpdate()
{
	player->DrawnUpdate();
}

void Snake::Draw()
{
	player->Draw();
}

