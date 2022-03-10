#pragma once

#include "../Engine/Structures/Game.h"

class Snake : public Game
{
public:
	Snake();
	~Snake() override;
	bool ExitGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
};

