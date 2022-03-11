#pragma once

#include <vector>
#include <Windows.h>

#include "../../Engine/Structures/IGameObject.h"

class Player : public IGameObject
{
public:

private:
	static constexpr char bodyShape = 219;

	std::vector<COORD> bodyParts;
	short startLenght;

	COORD moveDirection;

	static constexpr float movementSpeed = 0.2; //seconds per buffer Cell
	float secondCounter;
	bool drawNext;

public:
	Player(short _startLength);
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;

private: 

};

