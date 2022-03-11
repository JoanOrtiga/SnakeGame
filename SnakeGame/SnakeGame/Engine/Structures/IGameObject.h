#pragma once

class IGameObject
{
public:
	virtual ~IGameObject() {}
	virtual void Update(double dt) = 0;
	virtual void DrawnUpdate() = 0;
	virtual void Draw() = 0;
};

