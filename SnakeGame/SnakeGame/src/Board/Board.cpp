#include "Board.h"

#include "LamterEngine/Console/ConsoleController.h"

Board::Board()
{
	highscorePosition = { short(Lamter::ConsoleController::GetConsoleBufferSize().x - highscoreText.length() - 8), scoreSize };

	NewGame();
	UpdateHighScore(0);
}

void Board::NewGame()
{
	Lamter::ConsoleController::CLS();
	DrawBoard();
	UpdateScore(0);
}

void Board::Update(double dt)
{

}

void Board::DrawnUpdate()
{

}

void Board::Draw()
{

}

void Board::UpdateScore(int score)
{
	Lamter::ConsoleController::DrawAt(std::to_string(score), scorePosition.x + scoreText.length(), scorePosition.y);
}

void Board::UpdateHighScore(int score)
{
	Lamter::ConsoleController::DrawAt(std::to_string(score), highscorePosition.x + highscoreText.length(), highscorePosition.y);
}

void Board::GameLost()
{
	Lamter::ConsoleController::CLS();
	Lamter::ConsoleController::DrawAt("Game Lost", Lamter::ConsoleController::GetConsoleBufferSize().x / 2 - 4, Lamter::ConsoleController::GetConsoleBufferSize().y / 2);
	std::string exitMessage = "Press button 'C' to continue, or ESC, to close";
	Lamter::ConsoleController::DrawAt(exitMessage, Lamter::ConsoleController::GetConsoleBufferSize().x / 2 - exitMessage.length() / 2 , Lamter::ConsoleController::GetConsoleBufferSize().y / 2 + 2);
}

void Board::DrawBoard()
{
	Lamter::ConsoleController::DrawAt(cornerTopLeft, 0, 0);
	Lamter::ConsoleController::Fill(flatHorizontal, Lamter::ConsoleController::GetConsoleBufferSize().x - 1);
	Lamter::ConsoleController::Draw(cornerTopRight);

	for (short i = 1; i < scoreSize + 1; ++i)
	{
		Lamter::ConsoleController::Draw(flatVertical);
		Lamter::ConsoleController::DrawAt(flatVertical, Lamter::ConsoleController::GetConsoleBufferSize().x - 1, i);
	}

	Lamter::ConsoleController::Draw(verticalWithRight);
	Lamter::ConsoleController::Fill(flatHorizontal, Lamter::ConsoleController::GetConsoleBufferSize().x - 1);
	Lamter::ConsoleController::Draw(verticalWithLeft);

	for (short i = 2+scoreSize; i < Lamter::ConsoleController::GetConsoleBufferSize().y - 1; ++i)
	{
		Lamter::ConsoleController::Draw(flatVertical);
		Lamter::ConsoleController::DrawAt(flatVertical, Lamter::ConsoleController::GetConsoleBufferSize().x - 1, i);
	}

	Lamter::ConsoleController::Draw(cornerBottomLeft);
	Lamter::ConsoleController::Fill(flatHorizontal, Lamter::ConsoleController::GetConsoleBufferSize().x-1);
	Lamter::ConsoleController::Draw(cornerBottomRight);

	Lamter::ConsoleController::DrawAt(scoreText, scorePosition);
	Lamter::ConsoleController::DrawAt(highscoreText, highscorePosition);
}

bool Board::IsColliding(Lamter::COORD _position)
{
	if (_position.x <= 1 || _position.x >= Lamter::ConsoleController::GetConsoleBufferSize().x-2)
		return true;
	if (_position.y <= 1 + scoreSize || _position.y >= Lamter::ConsoleController::GetConsoleBufferSize().y-2)
		return true;

	return false;
}


