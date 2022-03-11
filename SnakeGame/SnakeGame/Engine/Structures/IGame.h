#pragma once

class IGame
{
public:
	virtual ~IGame(){};
	/**
	 * \brief controls game loop
	 * \return true if game is finished, false  otherwise
	 */
	virtual void Init() = 0;
	virtual bool ExitGame() = 0;
	virtual void Update(double dt) = 0;
	virtual void DrawnUpdate() = 0;
	virtual void Draw() = 0;
};

