#pragma once
#include <memory>
#include <string>

#include "CalculationEngine.h"
#include "MathExpression.h"
#include "RpnStrategy.h"

class Calculator {
 private:
  std::string string;
  bool isBlank();

 public:
  Calculator(std::string str);
  double getAnswer();
};
