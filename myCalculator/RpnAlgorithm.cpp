#include "RpnAlgorithm.h"

RpnAlgorithm::RpnAlgorithm()
    : inputString(), outputString(), stackWithOperators() {}
RpnAlgorithm::RpnAlgorithm(Separator separator) {
  inputString = separator.getOutputString();
}

MathExpression RpnAlgorithm::convertStringUsingAlgorithm() {
  for (int i = 0; i < inputString.getSize(); i++) {
    if (inputString[i] == ' ') {
      continue;
    }
    if (inputString.isEmpty()) {
      return MathExpression();
    }

    if (inputString.isOperand(inputString[i])) {
      while (i < inputString.getSize() &&
             inputString.isOperand(inputString[i])) {
        outputString += inputString[i];
        ++i;
      }
      outputString += ' ';
      --i;
    }
    if (inputString.isUnaryOperator(inputString[i]) ||
        inputString.isBinaryOperator(inputString[i])) {
      while (topOperatorHasHigherPrecedence(inputString[i]) &&
             (!isUnaryMinus(inputString[i]))) {
        appendTopOperatorToOutputString();
      }
      stackWithOperators.push(inputString[i]);
    }

    else if (inputString.isOpenParenthesis(inputString[i])) {
      stackWithOperators.push(inputString[i]);
    }

    else if (inputString.isCloseParenthesis(inputString[i])) {
      if (stackWithOperators.empty()) {
        throw std::runtime_error(
            "Mismatched parentheses: too many closing parentheses.");
      }
      while (!stackWithOperators.empty() &&
             !inputString.isOpenParenthesis(stackWithOperators.top())) {
        appendTopOperatorToOutputString();
      }

      if (!stackWithOperators.empty() &&
          inputString.isOpenParenthesis(stackWithOperators.top())) {
        stackWithOperators.pop();
      } else {
        throw std::runtime_error(
            "Mismatched parentheses: no matching opening parenthesis.");
      }
    }
  }

  while (!stackWithOperators.empty()) {
    appendTopOperatorToOutputString();
  }
  return outputString;
}

bool RpnAlgorithm::topOperatorHasHigherPrecedence(char someOperator) {
  return (!stackWithOperators.empty() &&
          inputString.precedence(stackWithOperators.top()) >=
              inputString.precedence(someOperator) &&
          !inputString.isOpenParenthesis(stackWithOperators.top()));
}
void RpnAlgorithm::appendTopOperatorToOutputString() {
  outputString += stackWithOperators.top();
  outputString += ' ';
  stackWithOperators.pop();
}
MathExpression RpnAlgorithm::getOutputString() { return outputString; }
