#pragma once
#include "RpnAlgorithm.h"
#include "ICalculate.h"
#include <stack>
#include <iostream>
#include "DivisionByZeroException.h"

class CalculateFromRPN : public ICalculate {
private:
	MathExpression rpnString;
	double answer;
	std::stack<double> stackWithOperands;

	std::string getToken(int& position);
	void count(char token);

public:
	CalculateFromRPN();
	CalculateFromRPN(RpnAlgorithm rpn);
	double evaluate();
};
