#include "Score.h"

Score::Score(Board* _board) : board(_board)
{
	NewGame();
}

int Score::GetCurrentScore()
{
	return currentScore;
}

void Score::UpdateScore()
{
	currentScore += scoreXFood;
	board->UpdateScore(currentScore);
}

void Score::SetHighScore()
{
	highScore = currentScore;
	board->UpdateHighScore(highScore);
}

void Score::NewGame()
{
	currentScore = 0;
}
