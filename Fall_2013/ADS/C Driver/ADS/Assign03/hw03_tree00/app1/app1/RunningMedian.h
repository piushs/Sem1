#pragma once

#include "Interfaces03.h"

class RunningMedian : IRunningMedian
{
public:
	RunningMedian(){};
	~RunningMedian(){};

	std::vector<int> compute(std::vector<int> vec, int window_size);
};