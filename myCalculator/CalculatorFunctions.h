#pragma once
#include <iostream>
#include <stack>
#include <string>
namespace CalculatorNS
{
	class Calculator
	{
	public:
		Calculator(const std::string& s);
		double Calculate();
	private:
		std::string expression;
		bool IsOperator(char c);
		bool IsOperand(char c);
		int Precedence(char c);
		std::string InfixToRPN(const std::string& expression);
		void Count(std::stack<double>& operands, std::string token, char token_0);
		double EvaluateRPN(const std::string& rpn);
	};
}