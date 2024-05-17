#include "Calculator.h"

calculator::calculator(std::string exp) : exp(exp)
{}

double calculator::getAnswer() {
	try {
		mathExpression expression;
		expression.setExpression(exp);

		ReversePolishNotation rpn;
		rpn.toRPN(expression);

		Calculate answer;
		answer.evaluate(rpn);
		return answer.answer;
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
	
}

