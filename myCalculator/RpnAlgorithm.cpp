#include "RpnAlgorithm.h"

RpnAlgorithm::RpnAlgorithm() : inputString() {}
RpnAlgorithm::RpnAlgorithm(MathExpression exp) : inputString(exp) {}

MathExpression RpnAlgorithm::convertStringUsingAlgorithm() {
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
        outputString += inputString[i];
        ++i;
        if (inputString[i] == ',') {
          outputString += '.';
          ++i;
        }
      }
      outputString += ' ';
      --i;
    }

    if (inputString.isUnaryMinus(inputString, i)) {
      stackWithOperators.push(
          inputString.getSymbolDenotingUnaryOperation(inputString[i]));
    }

    else if (inputString.isBinaryOperator(inputString[i])) {
      while (topOperatorHasHigherPrecedence(inputString[i])) {
        appendTopOperatorToOutputString();
      }
      stackWithOperators.push(inputString[i]);
    }

    else if (inputString.isLetter(inputString[i])) {
      std::string token;
      while (i < inputString.getSize() &&
             inputString.isLetter(inputString[i])) {
        token += inputString[i];
        ++i;
      }
      --i;
      if (inputString.isUnaryOperator(token)) {
        while (topOperatorHasHigherPrecedence(token)) {
          appendTopOperatorToOutputString();
        }
        stackWithOperators.push(
            inputString.getSymbolDenotingUnaryOperation(token));
      }
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
bool RpnAlgorithm::topOperatorHasHigherPrecedence(std::string someOperator) {
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
