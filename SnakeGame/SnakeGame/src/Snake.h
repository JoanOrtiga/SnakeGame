#pragma once

#include "../Engine/Structures/IGame.h"
#include "Player/Player.h"

class Snake : public IGame
{
private:
	Player* player;

public:
	Snake();
	~Snake() override;
	bool ExitGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
};

