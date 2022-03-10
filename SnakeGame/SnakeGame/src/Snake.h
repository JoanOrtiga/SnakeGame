#pragma once

#include "../Engine/Structures/IGame.h"

class Snake : public IGame
{
public:
	Snake();
	~Snake() override;
	bool ExitGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
};

