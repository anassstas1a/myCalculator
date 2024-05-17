#pragma once
#include "Calculate.h"
#include "ReversePolishNotation.h"
#include "mathExpression.h"

class calculator {
public:
	std::string exp;

	calculator(std::string exp);
	double getAnswer();
};



