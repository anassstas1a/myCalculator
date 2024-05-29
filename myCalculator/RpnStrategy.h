#pragma once
#include "Strategy.h"
#include "RpnAlgorithm.h"
#include"MathExpression.h"
#include "CalculateFromRPN.h"

class RpnStrategy : public Strategy
{
private:
	MathExpression expressionString;
	RpnAlgorithm rpnString;
	CalculateFromRPN answer;
public:
	RpnStrategy(std::string str);
	RpnStrategy(MathExpression str);
	double evaluate();
};