#include "ReversePolishNotation.h"

std::string ReversePolishNotation::toRPN(mathExpression inputString) {
	for (int i = 0; i < inputString.getSize(); i++) {
		if (inputString[i] == ' ') {
			continue;
		}
		if (inputString.isEmpty()) {
			return "";
		}

		if (IsOperand(inputString[i])) {
			while (i < inputString.getSize() && IsOperand(inputString[i])) {
				if (inputString[i] == ',')
				{
					outputString += '.';
					i++;
				}
				else {
					outputString += inputString[i];
					++i;
				}
			}
			outputString += ' ';
			--i;
		}
		else if (IsOperator(inputString[i])) {
			while (!stackWithOperators.empty() && Precedence(stackWithOperators.top()) >= Precedence(inputString[i]) && !isOpenParenthesis(stackWithOperators.top())) {
				outputString += stackWithOperators.top();
				outputString += ' ';
				stackWithOperators.pop();
			}
			stackWithOperators.push(inputString[i]);
		}

		else if (isOpenParenthesis(inputString[i])) {
			stackWithOperators.push(inputString[i]);
		}
		else if (isCloseParenthesis(inputString[i])) {
			while (!isOpenParenthesis(stackWithOperators.top())) {
				outputString += stackWithOperators.top();
				outputString += ' ';
				stackWithOperators.pop();
			}
			stackWithOperators.pop();
		}
	}

	while (!stackWithOperators.empty()) {
		outputString += stackWithOperators.top();
		outputString += ' ';
		stackWithOperators.pop();
	}

	return outputString;
}

int ReversePolishNotation::Precedence(char symbol) {
	if (symbol == '+' || symbol == '-') return 1;
	if (symbol == '*' || symbol == '/') return 2;
	if (symbol == '(') return 3;
}

bool ReversePolishNotation::IsOperator(char symbol) {
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}
bool ReversePolishNotation::IsOperand(char symbol) {
	return isdigit(symbol) || symbol == ',' || symbol == '.';
}
bool ReversePolishNotation::isEmpty() const {
	return outputString.empty();
}

bool ReversePolishNotation::isOpenParenthesis(char symbol) {
	return (symbol == '(');
}
bool ReversePolishNotation::isCloseParenthesis(char symbol) {
	return (symbol == ')');
}
int ReversePolishNotation::getSize() const {
	return outputString.size();
}
char ReversePolishNotation::operator[](int i) {
	return outputString[i];
}
