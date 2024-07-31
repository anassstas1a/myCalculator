#pragma once
#include <iostream>
#include <stack>

#include "DivisionByZeroException.h"
#include "ICalculate.h"
#include "RpnAlgorithm.h"

class CalculateFromRPN : public ICalculate {
 private:
  MathExpression rpnString;
  double answer;
  std::stack<double> stackWithOperands;

  std::string getToken(int& position);
  void countUnary(char token);
  void countBinary(char token);
  void countTrigonometric(char token);

 public:
  virtual ~CalculateFromRPN();
  CalculateFromRPN();
  CalculateFromRPN(RpnAlgorithm rpn);
  double evaluate() override;
};
