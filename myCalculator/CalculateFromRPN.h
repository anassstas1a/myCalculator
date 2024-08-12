#pragma once
#include <functional>
#include <iostream>
#include <stack>
#include <string>

#include "DivisionByZeroException.h"
#include "ICalculate.h"
#include "RpnAlgorithm.h"

class CalculateFromRPN : public ICalculate {
 private:
  MathExpression rpnString;
  double answer;
  std::stack<double> stackWithOperands;

  std::string getToken(int& position);
  void calculateUnary(char token);
  void calculateBinary(char token);

 public:
  virtual ~CalculateFromRPN();
  CalculateFromRPN();
  CalculateFromRPN(RpnAlgorithm rpn);
  double evaluate() override;
};
