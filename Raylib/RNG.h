#pragma once
#pragma once
#include <random>
#include <chrono>
#include <ctime>

static class RNG
{
	RNG();
public:
	static float get_rand(float lowBound, float highBound);
private:
public:
private:
	static unsigned seed;
	static std::mt19937 _mt;
	static std::uniform_real_distribution<float> _urd;
};
