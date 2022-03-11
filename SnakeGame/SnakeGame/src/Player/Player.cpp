#include "Player.h"

#include <iostream>

#include "../../Engine/Console/ConsoleController.h"
#include "../../Engine/Input/InputManager.h"

Player::Player(short _startLength) : startLenght(_startLength),
moveDirection({1,0})
{
	COORD consoleSize = Lamter::ConsoleController::GetConsoleBufferSize();

	for (short i = 0; i < _startLength; i++)
	{
		COORD startPosition = {(short)(consoleSize.X / 2) - i, (short)(consoleSize.Y / 2)};
		bodyParts.push_back(startPosition);
	}
}

void Player::Update(double dt)
{
	if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::W))
		moveDirection = { 0, -1 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::S))
		moveDirection = { 0, 1 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::A))
		moveDirection = { -1, 0 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::D))
		moveDirection = { 1, 0 };

	secondCounter -= dt;
	if (secondCounter <= 0.0)
	{
		secondCounter = movementSpeed;
		drawNext = true;
	}
}

void Player::DrawnUpdate()
{
	if (drawNext)
	{
		for(int i = bodyParts.size()-1; i > 1; --i)
		{
			bodyParts[i] = bodyParts[i - 1];
		}

		bodyParts[0] = { short(bodyParts[0].X + moveDirection.X), short(bodyParts[0].Y + moveDirection.Y) };
	}
}

void Player::Draw()
{
	if(drawNext)
	{
		for (int i = bodyParts.size() - 1; i > 1; --i)
		{
			//Lamter::ConsoleController::DrawAt(bodyShape, partPosition);
		}
	}
}

