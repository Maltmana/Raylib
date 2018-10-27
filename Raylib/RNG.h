#pragma once
#pragma once
#include <random>
#include <chrono>
#include <ctime>

static class RNG
{
	RNG();
public:
	static float get_randf(float lowBound, float highBound);
	static float get_randi(int lowBound, int highBound);
private:
public:
private:
	static unsigned seed;
	static std::mt19937 _mt;
	static std::uniform_real_distribution<float> _urd;
	static std::uniform_int_distribution<int> _uid;
};
