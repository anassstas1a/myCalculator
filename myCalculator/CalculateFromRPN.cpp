#include "CalculateFromRPN.h"

CalculateFromRPN::~CalculateFromRPN() = default;

CalculateFromRPN::CalculateFromRPN() : rpnString(), answer(0) {}

CalculateFromRPN::CalculateFromRPN(RpnAlgorithm rpn) {
  rpnString = rpn.getOutputString();
  answer = 0;
}

double CalculateFromRPN::evaluate() {
  for (int i = 0; i < rpnString.getSize(); i++) {
    if (rpnString[i] == ' ') {
      continue;
    }

    std::string token;
    if (rpnString.isOperand(rpnString[i])) {
      token = getToken(i);
      // std::cout << "TOKEN = " << token << '\n';
      stackWithOperands.push(std::stod(token));

    } else if (rpnString.isUnaryOperator(rpnString[i])) {
      token = rpnString[i];
      // std::cout << "TOKEN = " << token << '\n';
      countUnary(token[0]);
    } else if (rpnString.isBinaryOperator(rpnString[i])) {
      token = rpnString[i];
      // std::cout << "TOKEN = " << token << '\n';
      countBinary(token[0]);
    } else if (rpnString.isTrigonometricChar(rpnString[i])) {
      token = rpnString[i];
      // std::cout << "TOKEN = " << token << '\n';
      countTrigonometric(token[0]);
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

void CalculateFromRPN::countUnary(char token) {
  double firstOperand = stackWithOperands.top();
  stackWithOperands.pop();
  double result;
  switch (token) {
    case '#':
      result = -(firstOperand);
      break;
  }
  stackWithOperands.push(result);
}

void CalculateFromRPN::countTrigonometric(char token) {
  double firstOperand = stackWithOperands.top();
  stackWithOperands.pop();
  double result;
  switch (token) {
    case 's':
      result = sin(firstOperand);
      break;
    case 'c':
      result = cos(firstOperand);
      break;
    case 't':
      result = tan(firstOperand);
      break;
    case 'g':
      result = cos(firstOperand) / sin(firstOperand);
      break;
  }
  stackWithOperands.push(result);
}

void CalculateFromRPN::countBinary(char token) {
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
    case '^':
      result = pow(firstOperand, secondOperand);
      break;
  }
  stackWithOperands.push(result);
}
