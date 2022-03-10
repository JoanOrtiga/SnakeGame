#pragma once

namespace Lamter
{
	class Random
	{
	private:
		static char* abecedary;


	public:
		Random() = delete;

		static int GetRandomNumberInRange(int min, int max);
		static char GetRandomLetter();
		static void SetSeed(int seed);
		static void Init();
		static int GetRandomNumber();

	private:

	};
}

