#pragma once
#include "Strategy.h"
#include <memory>
#include <algorithm>


class CalculationEngine
{
private:
	std::unique_ptr<Strategy> engine;
public:
	void setCalculationEngine(std::unique_ptr<Strategy> newCalculatorEngine);
	CalculationEngine(std::unique_ptr<Strategy> newCalculatorEngine);
	double answer();
};