#include "Calculate.h"

double Calculate::evaluate(ReversePolishNotation rpnString) {
	if (rpnString.isEmpty()) {
		throw std::exception("string is empty");
	}
	for (int i = 0; i < rpnString.getSize(); i++) {

		if (rpnString[i] == ' ') {
			continue;
		}

		std::string token;
		if (rpnString.IsOperand(rpnString[i])) {
			token = getToken(rpnString, i);
			stackWithOperands.push(std::stod(token));
		}
		else if (rpnString.IsOperator(rpnString[i])) {
			token = rpnString[i];
			count(token[0]);
		}
	}
	answer = stackWithOperands.top();
	return answer;
}

std::string Calculate::getToken(ReversePolishNotation rpnString, int& position) {
	std::string token;
	while (position < rpnString.getSize() && rpnString[position] != ' ') {
		token += rpnString[position];
		++position;
	}
	return token;
}

void Calculate::count(char token)
{
	double secondOperand = stackWithOperands.top();
	stackWithOperands.pop();
	double firstOperand = stackWithOperands.top();
	stackWithOperands.pop();

	double result;
	switch (token)
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
		if(secondOperand == 0)
			throw std::exception("devision by 0");
		result = firstOperand / secondOperand;
		break;
	}
	stackWithOperands.push(result);
}

static std::ostream& operator<< (std::ostream& os, Calculate& ans) {
	os << ans.answer;
	return os;
}