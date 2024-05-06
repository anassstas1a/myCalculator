#pragma once
#include "CalculatorFunctions.h"
namespace CalculatorNS
{
	Calculator::Calculator(const std::string& s) : expression(s) {}

	double Calculator::Calculate()
	{
		if (InfixToRPN(expression) == "")
		{
			std::cout << "Пустая строка";
			return 0;
		}
		return EvaluateRPN(InfixToRPN(expression));
	}

	bool Calculator::IsOperator(char c)
	{
		return c == '+' || c == '-' || c == '*' || c == '/';
	}

	bool Calculator::IsOperand(char c)
	{
		return isdigit(c) || c == ',' || c == '.';
	}

	int Calculator::Precedence(char c)
	{
		if (c == '+' || c == '-') return 1;
		if (c == '*' || c == '/') return 2;
	}

	std::string Calculator::InfixToRPN(const std::string& expression)
	{
		std::stack<char> operators;
		std::string output;
		for (size_t i = 0; i < expression.size(); i++)
		{
			if (expression.std::string::empty())
				return "";

			if (expression[i] == ' ')
				continue;

			if (IsOperand(expression[i]))
			{
				std::string operand;
				while (i < expression.size() && IsOperand(expression[i]))
					if (expression[i] == '.')
					{
						operand += ',';
						i++;
					}
					else
					{
						operand += expression[i++];
					}
				--i;
				output += operand + ' '; //пробелы между операндами и операциями
			}

			else if (IsOperator(expression[i]))
			{
				while (!operators.empty() && Precedence(expression[i]) <= Precedence(operators.top()))
				{
					output += operators.top();
					operators.pop();
					output += ' ';
				}
				operators.push(expression[i]); // если оператор по приоритету больше то просто добавляем без проверки
			}
		}
		while (!operators.empty())
		{
			output += operators.top();
			operators.pop();
			output += ' ';
		}
		return output;
	}

	void Calculator::Count(std::stack<double>& operands, std::string token, char token_0)
	{
		double secondOperand = operands.top();
		operands.pop();
		double firstOperand = operands.top();
		operands.pop();

		double result;
		switch (token_0)
		{
		case '+':
			result = firstOperand + secondOperand;
			break;
		case '-':
			result = firstOperand - secondOperand;
			break;
		case '*':
			result = firstOperand * secondOperand;
			break;
		case '/':
			result = firstOperand / secondOperand;
			break;
		}
		operands.push(result);
	}

	double Calculator::EvaluateRPN(const std::string& rpn)
	{
		std::stack<double> operands;
		size_t pos = 0;

		while (pos < rpn.size())
		{
			if (rpn[pos] == ' ')
			{
				++pos;
				continue;
			}
			std::string token;

			while (pos < rpn.size() && rpn[pos] != ' ')
				token += rpn[pos++];
			char token_0 = token[0];

			if (IsOperand(token_0))
			{
				operands.push(std::stod(token));
			}
			else if (IsOperator(token_0))
			{
				Count(operands, token, token_0);
			}
			++pos;
		}
		return operands.top();
	}
}