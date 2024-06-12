#include "RpnAlgorithm.h"

RpnAlgorithm::RpnAlgorithm() : inputString() {}
RpnAlgorithm::RpnAlgorithm(MathExpression exp) : inputString(exp) {}

MathExpression RpnAlgorithm::conversionToAMachineReadableString() {
  for (int i = 0; i < inputString.getSize(); i++) {
    if (inputString[i] == ' ') {
      continue;
    }
    if (inputString.isEmpty()) {
      return MathExpression("");
    }

    if (inputString.isOperand(inputString[i])) {
      while (i < inputString.getSize() &&
             inputString.isOperand(inputString[i])) {
        if (inputString[i] == ',') {
          outputString += '.';
          i++;
        } else {
          outputString += inputString[i];
          ++i;
        }
      }
      outputString += ' ';
      --i;
    } else if (inputString.isOperator(inputString[i])) {
      while (!stackWithOperators.empty() &&
             inputString.precedence(stackWithOperators.top()) >=
                 inputString.precedence(inputString[i]) &&
             !inputString.isOpenParenthesis(stackWithOperators.top())) {
        outputString += stackWithOperators.top();
        outputString += ' ';
        stackWithOperators.pop();
      }
      stackWithOperators.push(inputString[i]);
    }

    else if (inputString.isOpenParenthesis(inputString[i])) {
      stackWithOperators.push(inputString[i]);
    } else if (inputString.isCloseParenthesis(inputString[i])) {
      while (!inputString.isOpenParenthesis(stackWithOperators.top())) {
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

MathExpression RpnAlgorithm::getOutputString() { return outputString; }
