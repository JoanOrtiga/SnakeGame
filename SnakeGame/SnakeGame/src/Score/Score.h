#pragma once

#include "../GameSettings.h"
#include "../Board/Board.h"

class Score
{
private:
	const int scoreXFood = GameSettings::scorePointsFood;
	int currentScore;
	int highScore;
	Board* board;

public:
	Score(Board* _board);
	int GetCurrentScore();
	void UpdateScore();
	void SetHighScore();
	void NewGame();
};

