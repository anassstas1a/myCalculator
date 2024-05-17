#include "mathExpression.h"

void mathExpression::setExpression(std::string s) {
	expression = s;
}
std::string mathExpression::getExpression() const {
	return expression;
}
int mathExpression::getSize() const {
	return expression.size();
}
bool mathExpression::isEmpty() const {
	return expression.std::string::empty();
}

char mathExpression::operator[](int i) {
	return expression[i];
}
