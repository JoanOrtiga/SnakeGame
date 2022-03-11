#include "Player.h"

#include <iostream>

#include "../../Engine/Console/ConsoleController.h"
#include "../../Engine/Input/InputManager.h"

Player::Player(short _startLength) : startLenght(_startLength),
moveDirection({ 1,0 })
{
	COORD consoleSize = Lamter::ConsoleController::GetConsoleBufferSize();
	headPosition.X = (short)consoleSize.X / 2;
	headPosition.Y = (short)consoleSize.Y / 2;
};

void Player::Update(double dt)
{
	if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::W))
		moveDirection = { 0, 1 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::S))
		moveDirection = { 0, -1 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::A))
		moveDirection = { -1, 0 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::D))
		moveDirection = { 1, 0 };

	headPosition.X = moveDirection.X;
	headPosition.Y = moveDirection.Y;

	secondCounter -= dt;
	if(secondCounter <= 0)
	{
		secondCounter = movementSpeed;
		drawNext = true;
	}
}

void Player::DrawnUpdate()
{
}

void Player::Draw()
{

	/*if(drawNext)
	{
		Lamter::ConsoleController::DrawAt(" ", headPosition);
		Lamter::ConsoleController::DrawAt(bodyShape, headPosition);
		drawNext = false;
	}*/
	
}
