#include "Player.h"

#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Input/InputManager.h"

#include "../Snake.h"

Player::Player(short _startLength, Snake* _snake, FoodController* _foodController, Board* _board, Score* _score) : startLenght(_startLength),
moveDirection({1,0}), foodController(_foodController), board(_board), score(_score), snake(_snake)
{
	Lamter::COORD consoleSize = Lamter::ConsoleController::GetConsoleBufferSize();

	for (short i = 0; i < _startLength; i++)
	{
		Lamter::COORD startPosition((consoleSize.x / 2) - i, (consoleSize.y / 2));
		bodyParts.push_back(startPosition);
	}
}

void Player::Update(double dt)
{
	Lamter::COORD lastMoveDirection = moveDirection;
	if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::W))
		moveDirection = { 0, -1 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::S))
		moveDirection = { 0, 1 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::A))
		moveDirection = { -1, 0 };
	else if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::D))
		moveDirection = { 1, 0 };

	if(moveDirection+bodyParts[0] == bodyParts[1])
	{
		moveDirection = lastMoveDirection;
	}

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
		tailLastPosition = bodyParts[bodyParts.size() - 1];

		for(int i = bodyParts.size()-1; i > 0; --i)
		{
			bodyParts[i] = bodyParts[i - 1];
		}

		bodyParts[0] = { bodyParts[0].x + moveDirection.x, bodyParts[0].y + moveDirection.y };

		if(board->IsColliding(bodyParts[0]) || IsColliding(bodyParts[0]))
		{
			if(IsColliding(bodyParts[0]))
				Lamter::ConsoleController::DrawAt("AAAAA", 0, 0);
			Die();
		}

		if(foodController->IsColliding(bodyParts[0]))
		{
			IncreaseLength();
			UpdateScore();
		}
	}
}

void Player::IncreaseLength()
{
	bodyParts.push_back(tailLastPosition);
}

void Player::Die()
{
	snake->PlayerDied();
}

void Player::UpdateScore()
{
	score->UpdateScore();
}

void Player::Draw()
{
	if(drawNext)
	{
		Lamter::ConsoleController::DrawAt(" ", tailLastPosition);

		for (const auto& bodyPart : bodyParts)
		{
			Lamter::ConsoleController::DrawAt(bodyShape, bodyPart);
		}

		drawNext = false;
	}
}

bool Player::IsColliding(Lamter::COORD _position)
{
	for (short i = 1; i < bodyParts.size(); ++i)
	{
		if (_position == bodyParts[i])
			return true;
	}
	return false;
}

