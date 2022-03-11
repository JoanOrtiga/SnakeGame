#pragma once

#include <Windows.h>
#include "../../Engine/Structures/IGameObject.h"

class Player : public IGameObject
{
public:

private:
	static constexpr char bodyShape = 219;

	COORD headPosition;
	short startLenght;

	COORD moveDirection;

	static constexpr float movementSpeed = 1; //seconds per buffer Cell
	float secondCounter;
	bool drawNext;

public:
	Player(short _startLength);
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;

private: 

};

