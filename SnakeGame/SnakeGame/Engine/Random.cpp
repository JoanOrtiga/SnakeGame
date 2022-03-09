#include "Random.h"

#include <cstdlib>
#include <ctime>

namespace Lamter
{
	#define ALPHABET_LENGTH 26
	char* Random::abecedary = new char[]
	{
		"QWERTYUIOPASDFGHJKLZXCVBNM"
	};

	void Random::Init()
	{
		srand(time(nullptr));
	}

	int Random::GetRandomNumber()
	{
		return rand();
	}

	int Random::GetRandomNumberInRange(int min, int max)
	{
		return min + (rand() % max);
	}

	char Random::GetRandomLetter()
	{
		return abecedary[rand() % ALPHABET_LENGTH];
	}

	void Random::SetSeed(int seed)
	{
		srand(seed);
	}
}


