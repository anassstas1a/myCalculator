#pragma once
#include <iostream>
#include <stack>
#include <string>

#include "IAlgorithm.h"
#include "MathExpression.h"

class RpnAlgorithm : public IAlgorithm {
 private:
  MathExpression inputString;
  MathExpression outputString;
  std::stack<char> stackWithOperators;

  bool topOperatorHasHigherPrecedence(char someOperator);
  bool topOperatorHasHigherPrecedence(std::string someOperator);
  void appendTopOperatorToOutputString();

 public:
  RpnAlgorithm();
  RpnAlgorithm(MathExpression exp);

  MathExpression convertStringUsingAlgorithm() override;
  MathExpression getOutputString();
};
