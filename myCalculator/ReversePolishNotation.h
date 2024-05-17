#pragma once
#include "mathExpression.h"
#include <stack>
#include <string>

class ReversePolishNotation
{
public:
	std::string outputString;
	std::stack<char> stackWithOperators;

	std::string toRPN(mathExpression inputString);

	int Precedence(char symbol);

	bool IsOperator(char symbol);
	bool IsOperand(char symbol);
	bool isEmpty() const;

	bool isOpenParenthesis(char symbol);
	bool isCloseParenthesis(char symbol);

	int getSize() const;
	char operator[](int i);
};