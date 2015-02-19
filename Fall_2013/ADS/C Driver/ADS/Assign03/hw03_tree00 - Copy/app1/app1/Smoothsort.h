#pragma once

#include "Interfaces03.h"


class SmoothSort : public ISmoothSort
{
public :
	SmoothSort(){};
	~SmoothSort(){};
	void buildHeap(std::vector<double>& vec) ;
    void sort(std::vector<double>& vec) ;
};