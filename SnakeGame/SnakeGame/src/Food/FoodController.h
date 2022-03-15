#pragma once

#include "LamterEngine/Structures/Collider.h"
#include "LamterEngine/Structures/IGameObject.h"
#include "LamterEngine/Timers/Timer.h"
#include "Food.h"

class FoodController : public Lamter::IGameObject, public Lamter::Collider
{
private:
		Lamter::Timer* spawnTimer;
		Food* foodPiece;

public:
	FoodController();
	void ReSpawnFood();
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	bool IsColliding(Lamter::COORD _position) override;
};

