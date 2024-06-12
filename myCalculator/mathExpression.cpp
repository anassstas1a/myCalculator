#include "MathExpression.h"

MathExpression::MathExpression(std::string str) : expression(str) {}

MathExpression::MathExpression(const MathExpression& e)
    : expression(e.getExpression()) {}

MathExpression::MathExpression() : expression("") {}

std::string MathExpression::getExpression() const { return expression; }
int MathExpression::getSize() const { return expression.size(); }
bool MathExpression::isEmpty() const { return expression.std::string::empty(); }

char MathExpression::operator[](int i) { return expression[i]; }
MathExpression MathExpression::operator+=(char c) { return expression += c; }

int MathExpression::precedence(char symbol) {
  if (symbol == '+' || symbol == '-') return 1;
  if (symbol == '*' || symbol == '/') return 2;
  if (symbol == '(') return 3;
}

bool MathExpression::isOperator(char symbol) {
  return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}
bool MathExpression::isOperand(char symbol) {
  return isdigit(symbol) || symbol == ',' || symbol == '.';
}
bool MathExpression::isOpenParenthesis(char symbol) { return (symbol == '('); }
bool MathExpression::isCloseParenthesis(char symbol) { return (symbol == ')'); }
