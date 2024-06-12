#pragma once
#include "CalculateFromRPN.h"
#include "MathExpression.h"
#include "RpnAlgorithm.h"
#include "Strategy.h"

class RpnStrategy : public Strategy {
 private:
  MathExpression expressionString;
  RpnAlgorithm rpnString;
  CalculateFromRPN answer;

 public:
  RpnStrategy(std::string str);
  RpnStrategy(MathExpression str);
  double evaluate();
};
