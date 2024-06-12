#include "CalculateFromRPN.h"

CalculateFromRPN::CalculateFromRPN() : rpnString(""), answer(0) {}

CalculateFromRPN::CalculateFromRPN(RpnAlgorithm rpn)
    : rpnString(rpn.getOutputString()), answer(0) {}

double CalculateFromRPN::evaluate() {
  for (int i = 0; i < rpnString.getSize(); i++) {
    if (rpnString[i] == ' ') {
      continue;
    }

    std::string token;
    if (rpnString.isOperand(rpnString[i])) {
      token = getToken(i);
      stackWithOperands.push(std::stod(token));
    } else if (rpnString.isOperator(rpnString[i])) {
      token = rpnString[i];
      count(token[0]);
    }
  }
  answer = stackWithOperands.top();
  return answer;
}

std::string CalculateFromRPN::getToken(int& position) {
  std::string token;
  while (position < rpnString.getSize() && rpnString[position] != ' ') {
    token += rpnString[position];
    ++position;
  }
  return token;
}

void CalculateFromRPN::count(char token) {
  double secondOperand = stackWithOperands.top();
  stackWithOperands.pop();
  double firstOperand = stackWithOperands.top();
  stackWithOperands.pop();

  double result;
  switch (token) {
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
      if (secondOperand == 0) {
        throw DivisionByZeroException();
      }
      result = firstOperand / secondOperand;
      break;
  }
  stackWithOperands.push(result);
}
