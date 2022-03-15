#include "Food.h"

#include <iostream>

#include "LamterEngine/Console/ConsoleController.h"

Food::Food(Lamter::COORD _initialPosition)
{
	position = _initialPosition;
}

void Food::UpdatePosition(Lamter::COORD _position)
{
	Lamter::ConsoleController::DrawAt(" ", position);
	position = _position;
}

void Food::Update(double dt)
{

}

void Food::DrawnUpdate()
{

}

void Food::Draw()
{
	Lamter::ConsoleController::DrawAt(foodCharacter, position);
}

bool Food::IsColliding(Lamter::COORD _position)
{
	if (position == _position)
		return true;
	return false;
}
