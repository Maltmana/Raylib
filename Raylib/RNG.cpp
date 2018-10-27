#include "RNG.h"

unsigned RNG::seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 RNG::_mt(seed);
std::uniform_real_distribution<float> RNG::_urd;
std::uniform_int_distribution<int> RNG::_uid;

float RNG::get_randf(float lowBound, float highBound)
{

	_urd.param(std::uniform_real_distribution<float>::param_type(lowBound, highBound));
	float result = _urd(_mt);
	return result;
}

float RNG::get_randi(int lowBound, int highBound)
{

	_uid.param(std::uniform_int_distribution<int>::param_type(lowBound, highBound));
	int result = _uid(_mt);
	return result;
}
