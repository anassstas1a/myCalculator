#include "MathExpression.h"
MathExpression::MathExpression() : expression() {}
MathExpression::MathExpression(std::string str) : expression(str) {}

const std::string& MathExpression::getExpression() const { return expression; }
std::string& MathExpression::getExpression() { return expression; }

int MathExpression::getSize() const { return expression.size(); }
bool MathExpression::isEmpty() const { return expression.empty(); }

char& MathExpression::operator[](int i) { return expression[i]; }
char MathExpression::operator[](int i) const { return expression[i]; }

MathExpression MathExpression::operator+=(char c) { return expression += c; }
MathExpression MathExpression::operator+=(std::string symbol) {
  return expression += symbol;
}
std::string::iterator MathExpression::begin() { return expression.begin(); }
std::string::iterator MathExpression::end() { return expression.end(); }

int MathExpression::precedence(char someOperator) {
  if (unaryOperators.find(someOperator) != unaryOperators.end()) {
    return unaryOperators[someOperator].precedence;
  } else if (binaryOperators.find(someOperator) != binaryOperators.end()) {
    return binaryOperators[someOperator].precedence;
  }
}

bool MathExpression::isUnaryMinus(MathExpression& inputString, int i) {
  return (inputString[i] == '-') &&
         (i == 0 || inputString[i - 1] == '(' ||
          inputString.isBinaryOperator(inputString[i - 1]) ||
          inputString.isUnaryOperator(inputString[i - 1]));
}
bool MathExpression::isUnaryOperator(char symbol) const {
  return unaryOperators.find(symbol) != unaryOperators.end();
}
bool MathExpression::isUnaryOperator(std::string symbol) const {
  return charUnaryOperators.find(symbol) != charUnaryOperators.end();
}
bool MathExpression::isBinaryOperator(char symbol) const {
  return binaryOperators.find(symbol) != binaryOperators.end();
}

char MathExpression::getCharUnaryOperator(std::string someOperator) {
  return charUnaryOperators[someOperator];
}
double MathExpression::calculateUnaryFunction(char someOperator, double x) {
  return unaryOperators[someOperator].function(x);
}
double MathExpression::calculateUnaryFunction(char someOperator, double a,
                                              double b) {
  return binaryOperators[someOperator].function(a, b);
}

bool MathExpression::isOperand(char symbol) {
  return isdigit(symbol) || symbol == '.' || isMath—onstants(symbol);
}
bool MathExpression::isMath—onstants(char symbol) {
  return (mathConstants.find(symbol) != mathConstants.end());
}
bool MathExpression::isOpenParenthesis(char symbol) { return (symbol == '('); }
bool MathExpression::isCloseParenthesis(char symbol) { return (symbol == ')'); }

double MathExpression::getMathConstantValue(char symbol) {
  return mathConstants[symbol];
}

double MathExpression::Sin(double x) {
  return (round(sin(x) * 1000000) / 1000000);
}
double MathExpression::Cos(double x) {
  return (round(cos(x) * 1000000) / 1000000);
}
double MathExpression::Tan(double x) { return (Sin(x) / Cos(x)); }
double MathExpression::Cot(double x) { return 1.0 / Tan(x); }
double MathExpression::division(double a, double b) {
  if (b == 0) {
    throw DivisionByZeroException();
  }
  return a / b;
}
int MathExpression::factorial(int n) {
  if (n < 0) throw std::runtime_error("Negative factorial is not defined");
  return (n <= 1) ? 1 : n * factorial(n - 1);
}
