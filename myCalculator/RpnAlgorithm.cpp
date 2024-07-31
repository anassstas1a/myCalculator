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

    // Если это оператор!

    if (inputString.isBinaryOperator(inputString[i])) {
      if ((inputString[i] == '-') &&
          (i == 0 || inputString[i - 1] == '(' ||
           inputString.isBinaryOperator(inputString[i - 1]) ||
           inputString.isUnaryOperator(inputString[i - 1]))) {
        stackWithOperators.push('#');
      } else {
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

    } else if (inputString.isLetter(inputString[i])) {
      std::string token;
      while (i < inputString.getSize() &&
             inputString.isLetter(inputString[i])) {
        token += inputString[i];
        ++i;
      }
      --i;
      // std::cout << "token = " << token << '\n';
      // std::cout << "token[0] = " << token[0] << '\n';
      // std::cout << "inputString.isTrigonometric(token)"
      //<< inputString.isTrigonometric(token) << '\n';
      if (inputString.isTrigonometric(token)) {
        while (!stackWithOperators.empty() &&

               inputString.precedence(stackWithOperators.top()) >=
                   inputString.precedence(token[0]) &&
               !inputString.isOpenParenthesis(stackWithOperators.top())) {
          outputString += stackWithOperators.top();
          outputString += ' ';
          stackWithOperators.pop();
        }
        stackWithOperators.push(token[0]);
      }
    } else if (inputString.isOpenParenthesis(inputString[i])) {
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
