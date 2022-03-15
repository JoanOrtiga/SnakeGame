#pragma once

#include <vector>

#include "LamterEngine/Classes/COORD.h"
#include "LamterEngine/Structures/IGameObject.h"
#include "LamterEngine/Structures/Collider.h"

#include "../Food/FoodController.h"
#include "../Board/Board.h"
#include "../Score/Score.h"
#include "../Snake.fwd.h"

class Player : public Lamter::IGameObject , public Lamter::Collider
{
public:

private:
	static constexpr char bodyShape = 219;

	std::vector<Lamter::COORD> bodyParts;
	short startLenght;
	Lamter::COORD tailLastPosition;

	Lamter::COORD moveDirection;

	static constexpr float movementSpeed = 0.2; //seconds per buffer Cell
	float secondCounter;
	bool drawNext;

	FoodController* foodController;
	Board* board;
	Score* score;
	Snake* snake;

public:
	Player(short _startLength, Snake* _snake, FoodController* _foodController, Board* _board, Score* _score);
	void Update(double dt) override;
	void DrawnUpdate() override;
	void IncreaseLength();
	void Die();
	void UpdateScore();
	void Draw() override;
	bool IsColliding(Lamter::COORD _position) override;

private: 

};

