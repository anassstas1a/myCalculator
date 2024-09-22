#include "CalculateFromRPN.h"

CalculateFromRPN::~CalculateFromRPN() = default;

CalculateFromRPN::CalculateFromRPN() : rpnString(), answer(0) {}

CalculateFromRPN::CalculateFromRPN(RpnAlgorithm rpn) {
  rpnString = rpn.getOutputString();
  answer = 0;
}

double CalculateFromRPN::calculate() {
  for (int i = 0; i < rpnString.getSize(); i++) {
    if (rpnString[i] == ' ') {
      continue;
    }

    std::string token;
    if (rpnString.isOperand(rpnString[i])) {
      token = getToken(i);
      if (rpnString.isMathÑonstants(token[0])) {
        stackWithOperands.push(rpnString.getMathConstantValue(token[0]));
      } else {
        stackWithOperands.push(std::stod(token));
      }

    } else if (rpnString.isUnaryOperator(rpnString[i])) {
      if (!stackWithOperands.empty()) {
        calculateUnary(rpnString[i]);
      } else {
        throw std::runtime_error("incorrectly entered expression.");
      }
    }

    else if (rpnString.isBinaryOperator(rpnString[i])) {
      if (stackWithOperands.size() >= 2) {
        calculateBinary(rpnString[i]);
      } else {
        throw std::runtime_error("incorrectly entered expression.");
      }
    }
  }
  answer = stackWithOperands.top();
  stackWithOperands.pop();
  if (!stackWithOperands.empty()) {
    throw std::runtime_error("incorrectly entered expression.");
  }
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

void CalculateFromRPN::calculateUnary(char token) {
  double firstOperand = stackWithOperands.top();
  stackWithOperands.pop();

  double result;
  result = rpnString.calculateUnaryFunction(token, firstOperand);
  stackWithOperands.push(result);
}

void CalculateFromRPN::calculateBinary(char token) {
  double secondOperand = stackWithOperands.top();
  stackWithOperands.pop();

  double firstOperand = stackWithOperands.top();
  stackWithOperands.pop();

  double result;
  result = rpnString.calculateUnaryFunction(token, firstOperand, secondOperand);
  stackWithOperands.push(result);
}
