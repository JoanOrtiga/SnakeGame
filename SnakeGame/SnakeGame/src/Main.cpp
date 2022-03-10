#include <iostream>

#include "../Engine/Engine/Engine.h"
#include "Snake.h"

using namespace Lamter;

#define TARGET_FPS 60

int main()
{
    Snake game;
    Engine engine(game, TARGET_FPS);
    engine.Run();
}