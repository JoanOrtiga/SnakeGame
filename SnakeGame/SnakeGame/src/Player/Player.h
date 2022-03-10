#pragma once

#include "../../Engine/Console/ConsoleController.h"
#include "../../Engine/Structures/IGameObject.h"

class Player : public IGameObject
{
public:

private:
	static constexpr char bodyShape = 219;

	COORD headPosition;
	

public:
	Player();
	void Update() override;
	void DrawnUpdate() override;
	void Draw() override;

private: 

};

