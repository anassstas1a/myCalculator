#pragma once
#include "Calculator.h"
#include <string>
#include "MathExpression.h"
#include <memory>
#include "RpnStrategy.h"
#include "CalculationEngine.h"

class Calculator
{
private:
	std::string string;
	bool isBlank();
public:
	Calculator(std::string str);
	double getAnswer();
};