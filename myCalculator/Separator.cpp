#include "Separator.h"

#include <iostream>

#include "MathExpression.h"

MathExpression Separator::separate() {
  for (int i = 0; i < inputString.getSize(); i++) {
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
    } else if (inputString.isUnaryOperator(inputString[i]) ||
               inputString.isBinaryOperator(inputString[i])) {
      if (inputString.isUnaryMinus(inputString, i)) {
        outputString += inputString.getCharUnaryOperator("-");
        outputString += ' ';
      } else if (std::isalpha(inputString[i])) {
        std::string token;
        while (i < inputString.getSize() && std::isalpha(inputString[i])) {
          token += inputString[i];
          ++i;
        }
        --i;
        if (inputString.isUnaryOperator(token)) {
          outputString += inputString.getCharUnaryOperator(token);
          outputString += ' ';
        }
      } else {
        outputString += inputString[i];
        outputString += ' ';
      }
    } else if (inputString.isOpenParenthesis(inputString[i]) ||
               inputString.isCloseParenthesis(inputString[i])) {
      outputString += inputString[i];
      outputString += ' ';
    }
  }
  return outputString;
}

MathExpression Separator::getOutputString() { return outputString; }
