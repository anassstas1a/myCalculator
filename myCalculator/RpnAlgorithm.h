#pragma once
#include <iostream>
#include <stack>
#include <string>

#include "IAlgorithm.h"
#include "MathExpression.h"
#include "Separator.h"

class RpnAlgorithm : public IAlgorithm {
 public:
  RpnAlgorithm();
  RpnAlgorithm(Separator separator);

  MathExpression convertStringUsingAlgorithm() override;
  MathExpression getOutputString();

 private:
  MathExpression inputString;
  MathExpression outputString;
  std::stack<char> stackWithOperators;

  bool isUnaryMinus(char symbol) { return symbol == '#'; }
  bool topOperatorHasHigherPrecedence(char someOperator);
  void appendTopOperatorToOutputString();
};
