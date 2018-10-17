#include "RNG.h"

unsigned RNG::seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 RNG::_mt(seed);
std::uniform_real_distribution<float> RNG::_urd;

float RNG::get_rand(float lowBound, float highBound)
{

	_urd.param(std::uniform_real_distribution<float>::param_type(lowBound, highBound));
	float result = _urd(_mt);
	return result;
}
