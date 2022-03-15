#include "FoodController.h"

#include <iostream>

#include "../GameSettings.h"
#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Engine/Random.h"

FoodController::FoodController()
{
	spawnTimer = new Lamter::Timer(GameSettings::repositionFoodTime, true, false, -1);
	Lamter::COORD spawnPosition = Lamter::Random::GetRandomCoord(3, 3, Lamter::ConsoleController::GetConsoleBufferSize().x - 2, Lamter::ConsoleController::GetConsoleBufferSize().y - 2);
	foodPiece = new Food(spawnPosition);
}

void FoodController::ReSpawnFood()
{
	Lamter::COORD spawnPosition = Lamter::Random::GetRandomCoord(3, 3, Lamter::ConsoleController::GetConsoleBufferSize().x - 2, Lamter::ConsoleController::GetConsoleBufferSize().y-2);
	foodPiece->UpdatePosition(spawnPosition);
}

void FoodController::Update(double dt)
{
	spawnTimer->Tick(dt);

}

void FoodController::DrawnUpdate()
{
	/*if (spawnTimer->IsReady())
	{
		ReSpawnFood();
	}*/

	foodPiece->DrawnUpdate();
}

void FoodController::Draw()
{
	foodPiece->Draw();
}

bool FoodController::IsColliding(Lamter::COORD _position)
{
	if(foodPiece->IsColliding(_position))
	{
		ReSpawnFood();
		return true;
	}
	return false;
}
