#pragma once
#include <memory>
#include <sstream>
#include <string>

#include "CalculationEngine.h"
#include "MathExpression.h"
#include "RpnStrategy.h"

class Calculator {
 private:
  MathExpression expression;
  double answer = 0;
  bool isSpace();

 public:
  Calculator(std::string str = "");
  double calculate();
  void addSymbol(std::string symbol);
  void deleteSymbol();
  std::string getDisplayText() const;
  std::string getAnswer() const;
  void clearExpression();
};
