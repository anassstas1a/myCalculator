#include "MathExpression.h"

MathExpression::MathExpression() : expression() {}

MathExpression::MathExpression(std::string str) : expression(str) {}

const std::string& MathExpression::getExpression() const { return expression; }
std::string& MathExpression::getExpression() { return expression; }

int MathExpression::getSize() const { return expression.size(); }
bool MathExpression::isEmpty() const { return expression.empty(); }

char MathExpression::operator[](int i) { return expression[i]; }
MathExpression MathExpression::operator+=(char c) { return expression += c; }

std::string::iterator MathExpression::begin() { return expression.begin(); }
std::string::iterator MathExpression::end() { return expression.end(); }

int MathExpression::precedence(char someOperator) {
  if (unaryOperators.find(someOperator) != unaryOperators.end()) {
    return unaryOperators[someOperator].precedence;
  } else if (binaryOperators.find(someOperator) != binaryOperators.end()) {
    return binaryOperators[someOperator].precedence;
  }
}
int MathExpression::precedence(std::string someOperator) {
  char symbol = unaryOp[someOperator].symbolDenotingUnaryOperation;
  return unaryOperators[symbol].precedence;
}

bool MathExpression::isLetter(char symbol) {
  return std::isalpha(static_cast<unsigned char>(symbol));
}
bool MathExpression::isUnaryMinus(MathExpression& inputString, int i) {
  return (inputString[i] == '-') &&
         (i == 0 || inputString[i - 1] == '(' ||
          inputString.isBinaryOperator(inputString[i - 1]));
}
bool MathExpression::isUnaryOperator(char symbol) {
  return (unaryOperators.find(symbol) != unaryOperators.end());
}
bool MathExpression::isUnaryOperator(std::string symbol) {
  return (unaryOp.find(symbol) != unaryOp.end());
}
bool MathExpression::isBinaryOperator(char symbol) {
  return (binaryOperators.find(symbol) != binaryOperators.end());
}

char MathExpression::getSymbolDenotingUnaryOperation(
    std::string someOperation) {
  return unaryOp[someOperation].symbolDenotingUnaryOperation;
}
char MathExpression::getSymbolDenotingUnaryOperation(char someOperation) {
  std::string s = std::string(1, someOperation);
  return unaryOp[s].symbolDenotingUnaryOperation;
}
double MathExpression::getUnaryFunction(char someOperator, double x) {
  return unaryOperators[someOperator].function(x);
}
double MathExpression::getBinaryFunction(char someOperator, double a,
                                         double b) {
  return binaryOperators[someOperator].function(a, b);
}

bool MathExpression::isOperand(char symbol) {
  return isdigit(symbol) || symbol == ',' || symbol == '.' || symbol == 'p';
}
bool MathExpression::isMath—onstants(char symbol) {
  return (math—onstants.find(symbol) != math—onstants.end());
}
bool MathExpression::isOpenParenthesis(char symbol) { return (symbol == '('); }
bool MathExpression::isCloseParenthesis(char symbol) { return (symbol == ')'); }

double MathExpression::getMath—onstant(char symbol) {
  return math—onstants[symbol];
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
