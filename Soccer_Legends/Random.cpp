#include "Random.h"
#include <random>



Random::Random()
{
}

// source: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range/7560564
int Random::randInt(int lower_bound, int upper_bound) {
	std::random_device rd;  // get a random number
	std::mt19937 seed(rd());  // seed generator
	std::uniform_int_distribution<> range(lower_bound, upper_bound);  // define the range

	return range(seed);
}