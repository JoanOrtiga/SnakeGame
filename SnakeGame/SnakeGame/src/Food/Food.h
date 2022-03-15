#pragma once

#include "LamterEngine/Structures/Collider.h"
#include "LamterEngine/Structures/IGameObject.h"

#include "../GameSettings.h"

class Food : public Lamter::IGameObject, public Lamter::Collider
{
private:
	Lamter::COORD position;
	int scorePoints = GameSettings::scorePointsFood;
	static constexpr char foodCharacter = '@';

public:
	Food(Lamter::COORD _initialPosition);
	void UpdatePosition(Lamter::COORD _position);
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	bool IsColliding(Lamter::COORD _position) override;
};

