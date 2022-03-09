#include <iostream>

#include "../Engine/Engine.h"

using namespace Lamter;

int main()
{
    Engine* engine = new Engine();

    while(true)
    {
        engine->Update();
    }
}