#include "LamterEngine/Engine/Engine.h"
#include "Snake.h"

using namespace Lamter;

#define TARGET_FPS 30

int main()
{
	Snake* game = new Snake();
	Engine engine(game, TARGET_FPS, {70, 30},false);
    engine.Run();
}