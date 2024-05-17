#pragma once
#include "ReversePolishNotation.h"
#include <stack>
#include <iostream>

class Calculate {
public:
	double answer = 0;
	std::stack<double> stackWithOperands;

	double evaluate(ReversePolishNotation rpnString);


	std::string getToken(ReversePolishNotation rpnString, int& position);

	void count(char token);
};

static std::ostream& operator<< (std::ostream& os, Calculate& ans);
