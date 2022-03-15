#include "Snake.h"

Snake::Snake() = default;

Snake::~Snake() = default;

#include "LamterEngine/Console/ConsoleController.h"

void Snake::Init()
{
	exitLoop = false;
	exitGame = false;
	board = new Board();
	score = new Score(board);
	foodController = new FoodController();
	player = new Player(5, this, foodController, board, score);
}

bool Snake::ExitGame()
{
	return exitGame;
}

bool Snake::ExitLoop()
{
	return exitLoop;
}

void Snake::Update(double dt)
{
	player->Update(dt);
	foodController->Update(dt);
}

void Snake::DrawnUpdate()
{
	player->DrawnUpdate();
	foodController->DrawnUpdate();

}

void Snake::Draw()
{
	player->Draw();
	foodController->Draw();
}

void Snake::PlayerDied()
{
	exitLoop = true;
	board->GameLost();
}

void Snake::NewGame()
{
	exitLoop = false;
	exitGame = false;
	board->NewGame();
	score->SetHighScore();
	score->NewGame();
	delete foodController;
	foodController = new FoodController();
	delete player;
	player = new Player(5, this, foodController, board, score);
	


}

