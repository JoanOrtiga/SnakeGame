#include "Player.h"

Player::Player()
{
	headPosition = { 0,0 };
}

void Player::Update()
{
}

void Player::DrawnUpdate()
{
}

void Player::Draw()
{
	Lamter::ConsoleController::DrawAt(bodyShape, headPosition);
}
