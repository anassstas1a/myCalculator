#pragma once
#include "MathExpression.h"
#include <stack>
#include <string>
#include "IAlgorithm.h"

class RpnAlgorithm : public IAlgorithm
{
private:
	MathExpression inputString;
	MathExpression outputString;
	std::stack<char> stackWithOperators;

public:
	RpnAlgorithm();
	RpnAlgorithm(MathExpression exp);

	MathExpression conversionToAMachineReadableString();
	MathExpression getOutputString();
};