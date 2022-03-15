#pragma once

#include "Board/Board.h"
#include "Food/FoodController.h"
#include "LamterEngine/Structures/IGame.h"
#include "Player/Player.h"

class Snake : public Lamter::IGame
{
private:
	Player* player;
	Board* board;
	FoodController* foodController;
	Score* score;

	bool exitGame;
	bool exitLoop;

public:
	Snake();
	~Snake() override;
	void Init() override;
	bool ExitGame() override;
	bool ExitLoop() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void PlayerDied();
	void NewGame() override;
};

