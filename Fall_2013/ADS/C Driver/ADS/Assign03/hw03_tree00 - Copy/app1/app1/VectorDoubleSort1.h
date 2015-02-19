#pragma once

#include "Interfaces03.h"

class VectorDoubleSort1 : public IVectorDoubleSort
{
public :
	VectorDoubleSort1() { }
    ~VectorDoubleSort1() { }
	void sort(std::vector<double>& vec);
};